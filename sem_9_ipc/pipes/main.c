#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefd[2];
    pid_t pid;
	const size_t BUFFER_LEN = 128;
    char buffer[BUFFER_LEN];

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // Child process
        // close(pipefd[1]); // Close the write end of the pipe
		
		int read_bytes = 0;
		do {
			read_bytes = read(pipefd[0], buffer, sizeof(buffer));
			printf("Child received: %s of %d bytes\n", buffer, read_bytes); // Print the message
		} while (read_bytes);
		
		close(pipefd[0]); // Close the read end of the pipe
    } else { // Parent process
        close(pipefd[0]); // Close the read end of the pipe
        const char *message = "Hello from parent!";
		// Wtite should also be in loop
	   	write(pipefd[1], message, strlen(message) + 1); // Write to the pipe
        close(pipefd[1]); // Close the write end of the pipe
        wait(NULL); // Wait for the child process to finish
    }

    return 0;
}
