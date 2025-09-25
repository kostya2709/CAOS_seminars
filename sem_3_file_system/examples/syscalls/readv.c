#include <stdio.h>
#include <stdlib.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // Open the file for reading
    int fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Define the buffers and their lengths
    char buffer1[10] = {};
    char buffer2[20] = {};
    struct iovec iov[2] = {};

    iov[0].iov_base = buffer1;
    iov[0].iov_len = sizeof(buffer1);
    iov[1].iov_base = buffer2;
    iov[1].iov_len = sizeof(buffer2);

    // Read data into the buffers
    ssize_t bytesRead = readv(fd, iov, 2);
    if (bytesRead == -1) {
        perror("readv");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Print the data read
    printf("Buffer 1: %.*s\n", (int)iov[0].iov_len, buffer1);
    printf("Buffer 2: %.*s\n", (int)iov[1].iov_len, buffer2);

    // Close the file
    close(fd);
    return 0;
}
