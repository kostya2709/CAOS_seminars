#define _GNU_SOURCE

#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>

static void* (*orig_malloc)(size_t ) = NULL;

void *malloc(size_t size)
{
	if (orig_malloc == NULL) {
		orig_malloc = (void*(*)(size_t))dlsym(RTLD_NEXT, "malloc");
	}
	
	{
		fprintf(stderr, "Hijacked malloc(%ld)\n", size);
	}
	
	void* alloc_addr = orig_malloc(size);
	return alloc_addr;
}
