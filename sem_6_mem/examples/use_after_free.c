#include <stdio.h>
#include <stdlib.h>

int main() {

	printf("Start\n");

	size_t N = 100;
	
	int* ptr = malloc(sizeof(int) * N);
	printf("ptr = %p\n", ptr);	
	
	free(ptr);

	ptr[5] = 0;	

}
