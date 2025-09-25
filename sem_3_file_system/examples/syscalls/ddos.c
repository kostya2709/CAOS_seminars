#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int maxFd() {
	return sysconf(_SC_OPEN_MAX);
}

void ddos() {
	int max_fd = maxFd();
	for (int i = 0; i < max_fd - 3; ++i) {
		open("foo.txt", O_RDONLY);
	}
}

int main() {
	printf("Max fd = %d\n", maxFd());
	ddos();

	const int READ_BYTES = 10;
	char data[100] = {};

    int fd = open("foo.txt", O_RDONLY);
    if (fd < 0) {
        perror("open");
        exit(1);
    }
 
    int len = read(fd, data, READ_BYTES);
    printf("read(%d, data, %d) -> %d bytes were read.\n",fd, READ_BYTES, len);
    data[len] = '\0';
    printf("data: %s\n", data);
 
    return 0;
}
