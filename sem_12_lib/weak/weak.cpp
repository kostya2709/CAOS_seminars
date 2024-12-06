#include <stdio.h>

int weak_foo(int x) {
	printf("Hacked\n");
	return 3 * x;	
}
