#include <stdio.h>
#include <dlfcn.h>
#include "dynamic_lib.h"

int main() {
	
	void* handle = dlopen("libdynamic.so", RTLD_LAZY);
	int (*func)(void) = dlsym(handle, "hello");
	int x = (*func)();
	dlclose(handle);
	
	printf("Main is correct %d\n", x);
	return 0;
}


