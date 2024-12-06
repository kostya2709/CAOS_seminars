#include <stdio.h>

int global_value1;
int global_value2;

void ruiner();

int main() {

	printf("global_value1 = %d\n", global_value1);
	printf("global_value2 = %d\n", global_value2);

	printf("Call ruiner\n");

	ruiner();

	printf("global_value1 = %d\n", global_value1);
	printf("global_value2 = %d\n", global_value2);

}
