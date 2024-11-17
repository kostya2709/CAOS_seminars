#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

#define FIFO_PATH "/tmp/myfifo" // Path to the named pipe

void writer_process() {
    int fd;
    char message[] = "Hello from named pipe!";

    fd = open(FIFO_PATH, O_WRONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    write(fd, message, strlen(message) + 1);
    printf("Message sent: %s\n", message);

    close(fd);
}

void reader_process() {
    int fd;
    char buffer[100];

    fd = open(FIFO_PATH, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    read(fd, buffer, sizeof(buffer));
    printf("Message received: %s\n", buffer);

    close(fd);
}

int main() {
    pid_t pid;

    if (mkfifo(FIFO_PATH, 0666) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) { // Child process
        writer_process();
    } else { // Parent process
        reader_process();
        wait(NULL);
        unlink(FIFO_PATH);
    }

    return 0;
}
