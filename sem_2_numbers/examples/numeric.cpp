#include <stdio.h>
#include <cstdint>
#include <arpa/inet.h>

void print_bytes( void* ptr, int num) {
	for (size_t i = 0; i < num; ++i) {
		printf("%x ", *((uint8_t*)ptr + i));
	}
	printf("\n");
}

int main() {
	uint32_t number = 1;
	printf("number = %u, 0x%x, 0o%o\n", number, number, number);
	print_bytes(&number, 4);
	
	uint32_t transformed = htonl(number);
	print_bytes(&transformed, 4);
}
