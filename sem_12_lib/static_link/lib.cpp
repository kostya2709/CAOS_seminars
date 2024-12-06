#include <stdio.h>

int global_int = 27;
int global_uninit;
int global_zero = 0;

static int global_static = 8;

struct Counter {
	int value;
	Counter() {
		printf("Created Counter\n");
	}
	~Counter() {
		printf("Destroyed Counter\n");
	}
};

void lib_foo() {
	static Counter counter;
	printf("Called lib_foo %d times (%p)\n", ++counter.value, &counter);
}

static void static_foo() {
	printf("static foo\n");
}	

