#include <iostream>
#include <stdio.h>

struct Empty {

};

// struct EmptyEmpty : Empty {

// };

void test_empty() {
	printf("sizeof(Empty) = %lu\n", sizeof(Empty));
	// printf("sizeof(EmptyEmpty) = %lu\n", sizeof(EmptyEmpty));
}

struct Test_int_char_double {
	int x;
	char y;
	// padding 3 bytes
	double z;
};

struct Test_int_double_char {
	int x;
	// padding 4 bytes
	double z;
	char y;
	// padding 7 bytes
};

void test_order() {
	printf("sizeof(Test_int_char_double) = %lu\n", sizeof(Test_int_char_double));
	printf("sizeof(Test_int_double_char) = %lu\n", sizeof(Test_int_double_char));
}

#pragma pack(push, 1)
struct Compressed {
	double d;
	char a;
	int x;
};
#pragma pack(pop)

struct Packed {
	int x;
	char y;
	double z;	
} __attribute__((packed));

struct alignas(64) alignas_32 {
	int x;
	char y;
	double z;	
};

void test_alignment() {
	printf("sizeof(Empty) = %lu, alignof(Empty) = %lu\n", sizeof(Empty), alignof(Empty));
	printf("sizeof(Test_int_char_double) = %lu, alignof(Test_int_char_double) = %lu\n", sizeof(Test_int_char_double), alignof(Test_int_char_double));
	printf("sizeof(Test_int_double_char) = %lu, alignof(Test_int_double_char) = %lu\n", sizeof(Test_int_double_char), alignof(Test_int_double_char));
	printf("sizeof(Compressed) = %lu, alignof(Compressed) = %lu\n", sizeof(Compressed), alignof(Compressed));
	printf("sizeof(Packed) = %lu, alignof(Packed) = %lu\n", sizeof(Packed), alignof(Packed));
	printf("sizeof(alignas_32) = %lu, alignof(alignas_32) = %lu\n", sizeof(alignas_32), alignof(alignas_32));
}

int main() {

	// test_empty();
	// test_order();
	test_alignment();
}
