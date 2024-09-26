#include <stdio.h>
#include <cstdint>

struct test {
	uint32_t first;
	long double second;
	uint16_t  third;
};


int main() {
	printf("sizeof(test) = %lu\n", sizeof(test));
	printf("alignof(test) = %lu\n", alignof(test));
}
