#include <stdio.h>

extern int sum(int x, int y);

int main() {
    int x = 9;
	int y = 18;
    printf("%d\n", sum(x, y));
}
