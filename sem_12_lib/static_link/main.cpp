#include <stdio.h>

extern int global_int;
extern int global_uninit;
extern int global_zero;

extern int global_static;
// static void static_foo();

void lib_foo();


int main() {

	printf("global_int = %d (%p)\n", global_int, &global_int);
	printf("global_uninit = %d (%p)\n", global_uninit, &global_uninit);
	printf("global_zero = %d (%p)\n", global_zero, &global_zero);
	
//	printf("global_static = %d (%p)\n", global_static, &global_static);

	lib_foo();
	printf("WORK\n");
	lib_foo();

//	static_foo();

}
