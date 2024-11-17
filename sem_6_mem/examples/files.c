#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#define MAX_LEN 1024

int main() {
    const char* filepath = "shared_file.txt";
	const int map_size = 4096;
    char msg_buffer[MAX_LEN] = {};
    char read_buffer[MAX_LEN] = {};

    // Open the file for reading and writing
    int fd = open(filepath, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    
    // Stretch the file size to the size of the message
    if (lseek(fd, MAX_LEN, SEEK_SET) == -1) {
        perror("Error stretching the file");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Write a dummy byte at the end to ensure the file has the correct size
    if (write(fd, "", 1) == -1) {
        perror("Error writing last byte of the file");
        close(fd);
        exit(EXIT_FAILURE);
    }
	lseek(fd, 0, SEEK_SET);

	// Map the file to memory
    char* const map = mmap(NULL, map_size, PROT_READ | PROT_WRITE, /*MAP_PRIVATE | MAP_ANONYMOUS*/ MAP_SHARED, fd, 0);
    if (map == MAP_FAILED) {
        perror("Error mmapping the file");
        close(fd);
        exit(EXIT_FAILURE);
    }


	while (1) {


		scanf("%s", msg_buffer);

		lseek(fd, 0, SEEK_SET);
		int bytes_read = read(fd, read_buffer, MAX_LEN - 1);
		if (bytes_read == -1) {
			perror("Error reading from file");
			close(fd);
			exit(EXIT_FAILURE);
		}
		read_buffer[bytes_read] = '\0';
		
		printf("File: %s\n", read_buffer);
		printf("mmap: %s\n", map);
		int msg_len = strlen(msg_buffer);

		// Write the message to the mapped memory
		memcpy(map, msg_buffer, msg_len);
		map[msg_len] = '\0';
		memset(msg_buffer, msg_len, 0);
	}

    // Clean up
    if (munmap(map, map_size) == -1) {
        perror("Error unmapping the file");
    }
    close(fd);

    return 0;
}

