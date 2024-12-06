#include <stdio.h>
#include "inline.h"
#include "template.h"
#include "weak.h"

void lib_foo() {
	int x = 4;
	printf("lib:inline_foo: 4 * x = %d\n", inline_foo(x));
	printf("lib:template_foo: 4 * x = %d\n", template_foo(x));
	printf("lib:weak_foo: 4 * x = %d\n", weak_foo(x));

}


