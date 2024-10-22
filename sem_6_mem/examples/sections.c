#include <stdio.h>

int global_uninit;   // bss
int global_zero = 0; // bss
int global_init = 1; // data

const int global_const = 5; // rodata

inline void foo() {
	int x = 0;
}

int main() { // text
    
	static int static_var = 5; // data
    int local_var; // stack

	foo();

	printf("global_init %p\n", &global_init);
	printf("global_zero %p\n", &global_zero);
	printf("global_uninit %p\n", &global_uninit);
	printf("global_const %p\n", &global_const);
    printf("static_var %p\n", &static_var);
    printf("local_var  %p\n", &local_var);
    printf("main       %p\n", &main);

	int x = 0;
	scanf("%d", &x);
}
