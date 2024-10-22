#include <stdio.h>
#include <stdlib.h>

int main() {
	printf("start\n");
	size_t N = 10000000000;
	int* ptr = malloc(sizeof(int) * N);
	printf("ptr = %p\n", ptr);
	free(ptr);
}
