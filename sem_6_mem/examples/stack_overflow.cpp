#include <stdio.h>

int foo(int x) {
	printf("%p\n", &x);
	foo(x + 1);
	return 1;
}

int main() {
	foo(1);
}
