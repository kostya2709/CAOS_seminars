#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

extern int errno;
 
int main() {
    // if file does not have in directory
    // then file foo.txt is created.
    int fd = open("foo.txt", O_RDONLY | O_CREAT, S_IRWXU | S_IRWXG);
 
    printf("fd = %d\n", fd);
 
    if (fd == -1) {
        // print which type of error is in the code
        printf("Error Number % d\n", errno);
 
        // print program detail "Success or failure"
        perror("Program");
		exit(1);
    }
	
	// Using close system Call
    if (close(fd) < 0) {
        perror("close:");
        exit(1);
    }
    printf("closed the fd.\n");
    
	return 0;
}
