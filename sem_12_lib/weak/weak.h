
// #pragma weak weak_foo

int __attribute__((weak)) weak_foo(int x) {
	return 2 * x;	
}
