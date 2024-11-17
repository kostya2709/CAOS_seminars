#include <stdio.h>

int main(int argc, char* argv[], char* env[]) {

	for (int i = 0; i < argc; ++i) {
		printf("argv[%d] = %s\n", i, argv[i]);
	}
	
	for (int i = 0; env[i]; ++i) {
		printf("env[%d] = %s\n", i, env[i]);
	}

	return 0;
}
