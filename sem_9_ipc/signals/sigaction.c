#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>


void handle_sigint(int sig, siginfo_t *siginfo, void *context) {
    printf("Caught signal %d (SIGINT) from process %ld\n", sig, (long)siginfo->si_pid);
//    exit(0);
}

int main() {
    struct sigaction sa;

    memset(&sa, 0, sizeof(sa));
    sa.sa_sigaction = handle_sigint;
    sa.sa_flags = SA_SIGINFO;

    // Register the signal handler for SIGINT
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    // Infinite loop to keep the program running
    while (1) {
        printf("Running... Press Ctrl+C to stop\n");
        sleep(1);
    }

    return 0;
}
