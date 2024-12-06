#define _GNU_SOURCE

#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>

void *malloc(size_t size)
{
    fprintf(stderr, "\nHijacked malloc(%ld)\n\n", size);
    return 0;
}
