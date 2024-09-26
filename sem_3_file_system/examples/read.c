#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	const int READ_BYTES = 10;
	char data[100] = {};

    int fd = open("foo.txt", O_RDONLY);
    if (fd < 0) {
        perror("r1");
        exit(1);
    }
 
    int len = read(fd, data, READ_BYTES);
    printf("read(%d, data, %d) -> %d bytes were read.\n",fd, READ_BYTES, len);
    data[len] = '\0';
    printf("data: %s\n", data);
 
    return 0;
}
