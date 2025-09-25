#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // Open the file for reading and writing
    int fd = open("example.txt", O_RDWR);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Write some data to the file
    const char *text = "Hello, World!";
    if (write(fd, text, 13) != 13) {
        perror("write");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Use lseek to move the file offset to the beginning
    if (lseek(fd, 0, SEEK_SET) == -1) {
        perror("lseek");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Read the data back from the file
    char buffer[14];
    if (read(fd, buffer, 13) != 13) {
        perror("read");
        close(fd);
        exit(EXIT_FAILURE);
    }
    buffer[13] = '\0'; // Null-terminate the string

    // Print the data read from the file
    printf("Read from file: %s\n", buffer);

    // Close the file
    close(fd);
    return 0;
}
