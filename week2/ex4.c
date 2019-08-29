#include <stdio.h>

void exchange(int *c, int *d){
	int temp = *c;
	*c = *d;
	*d = temp;
}

int main(){
	int a, b;
	printf("Enter first number:\n");
	scanf("%d", &a);
	printf("Enter second number:\n");
	scanf("%d", &b);

	exchange(&a, &b);
	printf("%d %d\n", a, b);
}
