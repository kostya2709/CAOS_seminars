#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

int main() {
	printf("start\n");
	size_t N = 10000000;
	size_t Nloop = 10000000000;
	for (size_t i = 0; i < Nloop; ++i) {
		int* ptr = calloc(N, 4);
		// int* ptr = mmap(NULL, N, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
		ptr[0] = 1;
		printf("i = %lu, ptr = %p\n", i, ptr);
	}
}
