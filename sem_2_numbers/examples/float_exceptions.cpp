#define _GNU_SOURCE
#include <stdio.h>
#include <fenv.h>
#include <math.h>
#include <float.h>

void print_exception_status() {
    printf("Exception status: ");
    if (fetestexcept(FE_DIVBYZERO)) printf("DIVBYZERO ");
    if (fetestexcept(FE_INVALID)) printf("INVALID ");
    if (fetestexcept(FE_OVERFLOW)) printf("OVERFLOW ");
    if (fetestexcept(FE_UNDERFLOW)) printf("UNDERFLOW ");
    if (fetestexcept(FE_INEXACT)) printf("INEXACT ");
    printf("\n");
}

void underflow() {
    printf("\n=== UNDERFLOW ===\n");
    feclearexcept(FE_ALL_EXCEPT);
    
    double tiny = DBL_MIN;  // Smallest normalized double
    printf("Smallest normalized double: %e\n", tiny);
    
    // Divide by a large number to cause gradual underflow
    double underflow_result = tiny / 1e300;
    printf("Result: %e\n", underflow_result);
    
    print_exception_status();
}

void overflow() {
    printf("\n=== OVERFLOW ===\n");
    feclearexcept(FE_ALL_EXCEPT);
    
    double huge = DBL_MAX;  // Largest representable double
    printf("Largest double: %e\n", huge);
    
    double overflow_result = huge * 2.0;
    printf("Result: %e\n", overflow_result);
    
    print_exception_status();
}

void division_by_zero() {
    printf("\n=== DIVISION BY ZERO ===\n");
    feclearexcept(FE_ALL_EXCEPT);
    
    double result = 1.0 / 0.0;
    printf("1.0 / 0.0 = %f\n", result);
    
    print_exception_status();
}

void invalid_operation() {
    printf("\n=== INVALID OPERATION ===\n");
    feclearexcept(FE_ALL_EXCEPT);
    
    double result = sqrt(-1.0);
    printf("sqrt(-1.0) = %f\n", result);
    
    print_exception_status();
}

int main() {
    // Enable all floating-point exceptions
	feenableexcept(FE_DIVBYZERO | FE_INVALID | FE_OVERFLOW | FE_UNDERFLOW);
    
    division_by_zero();
    invalid_operation();
    overflow();
    underflow();
    
    return 0;
}
