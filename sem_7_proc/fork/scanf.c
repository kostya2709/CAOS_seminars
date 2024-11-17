#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <sched.h>

size_t get_rsp() {
	size_t x = 0;
	return (size_t)(&x + 4); // ret_addr + rbp + 0x10
}

size_t get_rip() {
	size_t x = 0;
	return *(&x + 3);
}

int main() {
    pid_t pid = fork();

    if (pid == 0) {
		printf("child: Current rip = %lx, rsp = %lx\n", get_rip(), get_rsp());
		printf("I'm child process %d of proc %d!\n", getpid(), getppid());    
		int x = 0;
		scanf("%d", &x);
    } else {
		printf("parent: Current rip = %lx, rsp = %lx\n", get_rip(), get_rsp());
		printf("I'm parent process %d!\n", getpid());
        wait(NULL);
    }
    
    return 0;
}
