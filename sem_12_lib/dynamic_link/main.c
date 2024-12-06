#include <stdio.h>
#include "dynamic_lib.h"

int main() {
	int res = hello();
	printf("Main is correct %d\n", res);
	return 0;
}


