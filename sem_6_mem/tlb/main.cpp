#include <stdio.h>
#include <cstdlib>

void touch_array(int* array, size_t size) {
	for (size_t i = 0; i < size; ++i) {
		array[size] = 27;
	}
}

int main() {
	const size_t page_size = 4096;
	const size_t num_pages = 1000;
	const size_t size = page_size * num_pages;
	const size_t iter_num = 10000;
	
	int* array =(int*)malloc(sizeof(int) * size);
	
	
	for (size_t i = 0; i < iter_num; ++i) {
		touch_array(array, size);
	}
	
}
