#include <stdio.h>
#include <cstdint>

struct MyFloat {
	uint32_t frac : 23;
	uint32_t exp  : 8;
	uint32_t sign : 1;
};

int main() {
	float test = -1;
	MyFloat parsed = *(MyFloat*)&test;
	printf("sign: %x, exp: %x, frac: %x\n", parsed.sign, parsed.exp, parsed.frac);
}
