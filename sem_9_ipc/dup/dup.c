#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

void wait_input() {
	int x = 0;
	scanf("%d", &x);
}

int main() {

	printf("My pid = %d\n", getpid());

	int fd = open("file", O_RDONLY);
	int x = 0;
	wait_input();

	int new_fd = dup(fd);
	printf("new_fd = %d\n", new_fd);
	wait_input();

	close(fd);
	printf("Closed fd\n");
	wait_input();
}

