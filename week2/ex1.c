#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){
	int a;
	float b;
	double c;

	printf("size of int : %lu\n", sizeof(a));
        printf("size of float : %lu\n", sizeof(b));
        printf("size of double : %lu\n", sizeof(c));

	printf("INT_MAX: %d\n", INT_MAX);
	printf("FLOAT_MAX: %f\n", FLT_MAX);
	printf("DOUBLE_MAX: %f\n", DBL_MAX);
}
