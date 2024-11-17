#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <sched.h>

int main() {
    printf("One proc\n");
	pid_t pid = fork();
    if (pid == 0) {
		printf("I'm child process %d of proc %d!\n", getpid(), getppid());    
    } else {
		printf("I'm parent process %d!\n", getpid());
        wait(NULL);
    }
    
    return 0;
}
