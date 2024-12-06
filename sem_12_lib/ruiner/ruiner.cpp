
#pragma weak global_value1
double global_value1; // __attribute__((weak));

void ruiner() {
	global_value1 = 3.14159;
}
