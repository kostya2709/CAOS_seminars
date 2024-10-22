#include <stdio.h>
#include <stdlib.h>

int main() {
	size_t N = 10000;
	
	int x = 0;
	scanf("%d", &x);

	int* ptr = malloc(sizeof(int) * N);
	printf("ptr = %p\n", ptr);
	
	scanf("%d", &x);
	
	for (int i = 0; i < N; ++i) {
		ptr[i] = 0;
	}

	free(ptr);
}
