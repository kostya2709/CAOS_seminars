#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int read_buffer(int fd, char* buff, size_t buff_size)
{
    size_t total_read_bytes = 0;
    while (total_read_bytes < buff_size) {
        size_t read_bytes = read(fd, buff + total_read_bytes, buff_size - total_read_bytes);
        total_read_bytes += read_bytes;
        
		if (read_bytes == 0) {
            return total_read_bytes;
        }
        
		if ((read_bytes < 0) && (errno != EINTR)) {
            return -1;
        }
    }

    return total_read_bytes;
}

int main() {
    const size_t BUFF_SIZE = 4096;
    char buffer[BUFF_SIZE] = {};
    int read_count = read_buffer(0, buffer, BUFF_SIZE);
    
	printf("Read %d", read_count);
    
	return 0;
}
