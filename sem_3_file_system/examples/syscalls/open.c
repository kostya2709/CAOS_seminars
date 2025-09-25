#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

extern int errno;
 
int main() {
    int fd = open("foo1.txt", O_RDONLY | O_CREAT, S_IRWXU);
 
    printf("fd = %d\n", fd);
 
    if (fd == -1) {
        printf("Error Number % d\n", errno);
        perror("Program");
		exit(1);
    }
	
    if (close(fd) < 0) {
        perror("close:");
        exit(1);
    }
    printf("closed the fd.\n");
    
	return 0;
}
