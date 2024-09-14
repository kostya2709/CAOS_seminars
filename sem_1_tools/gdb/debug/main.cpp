
#include <stdio.h>

void foo_inner( int x1, int x2, int x3)
{
    printf( "x1 = %d;\nx1+x2 = %d;\nx1+x2+x3 = %d\n", x1, x2, x3);    
}

void foo_outer( int x1, int x2, int x3)
{
    int x;
    x3 = x1 + x2 + x3;
    x2 = x1 + x2;
    foo_inner( x1, x2, x);
}

int main()
{
    int x1 = 1;
    int x2 = 2;
    int x3 = 3;
    printf( "x1 = %d\nx2 = %d\nx3 = %d\n", x1, x2, x3);

    foo_outer( x1, x2, x3);

    return 0;
}

