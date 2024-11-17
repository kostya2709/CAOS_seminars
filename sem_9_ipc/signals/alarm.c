#include <unistd.h>
#include <stdio.h>

int main() {
	alarm(1);
	sleep(2);
	printf("Slept well\n");
}
