#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {

	// setvbuf(stdout, NULL, _IONBF, 0);
	printf("1. Now only one proc\n");
//	fflush(stdout);
		
    int pid = fork();
	switch(pid) {
        case -1:
            perror("fork");
            return -1;
        case 0:
            // Child
            printf("2. Child: parent pid = %i, my pid = %i, returned pid = %i\n", getppid(), getpid(), pid);
            break;
        default:
            // Parent
            printf("3. Parent: my pid = %i, returned pid = %i\n", getpid(), pid);
            break;
    }
    return 0;
}
