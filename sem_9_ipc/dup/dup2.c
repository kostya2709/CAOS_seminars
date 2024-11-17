#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

void wait_input() {
	int x = 0;
	scanf("%d", &x);
}

int main() {

	printf("My pid = %d\n", getpid());

	int fd = open("file", O_RDWR);
	wait_input();


	dprintf(fd, "Wrote from proc to file\n");
	wait_input();
	
	dup2(1, fd);
	dprintf(fd, "Wrote from proc to file\n");
	wait_input();

	close(fd);
	printf("Closed fd\n");
	wait_input();
}

