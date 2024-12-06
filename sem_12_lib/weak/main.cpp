#include <stdio.h>
#include "inline.h"
#include "template.h"
#include "weak.h"

void lib_foo();

int main() {

	int x = 3;
	printf("main:inline_foo: 2 * x = %d\n", inline_foo(x));
	printf("main:template_foo: 2 * x = %d\n", template_foo(x));
	printf("main:weak_foo: 2 * x = %d\n", weak_foo(x));

	lib_foo();

}


