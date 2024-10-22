#include <stdio.h>

extern int sum(int n);

int main() {
    int n = 0;
    scanf("%d", &n);
    printf("sum(%d) = %d\n", n, sum(n));
}
