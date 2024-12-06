#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    char* data = (char *)malloc(100);
    strncpy(data, "I will be back\0", 14);
    fprintf(stderr, "malloc(): %p\nStr: %s\n", data, data);
}
