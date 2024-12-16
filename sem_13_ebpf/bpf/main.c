#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <linux/if_ether.h>
#include <linux/filter.h>
#include <linux/if_packet.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>


int main() {

	struct sock_filter code[] = {
		{0x28, 0, 0, 0x0000000c},
		{0x15, 0, 1, 0x00000800},
		{0x06, 0, 0, 0x00040000},
		{0x06, 0, 0, 0x00000000},
	};	

	struct sock_filter code[] = {
        BPF_STMT(BPF_LD|BPF_H|BPF_ABS, 12),
        BPF_JUMP(BPF_JMP|BPF_JEQ|BPF_K, ETH_P_IP, 0, 1),
        BPF_STMT(BPF_RET|BPF_K, 0x00040000),
        BPF_STMT(BPF_RET|BPF_K, 0),
	};

	struct sock_fprog bpf = {
		.len = sizeof(code) / sizeof(code[0]),
		.filter = code,
	};

	int sock = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ALL));

	if (sock < 0) {
		perror("socket");
        exit(EXIT_FAILURE);
	}

	int ret = setsockopt(sock, SOL_SOCKET, SO_ATTACH_FILTER, &bpf, sizeof(bpf));
	if (ret < 0) {
		perror("setsockopt");
        close(sock);
        exit(EXIT_FAILURE);
	}

	close(sock);

}
