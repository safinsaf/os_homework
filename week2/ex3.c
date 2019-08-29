#include <stdio.h>
#include <string.h>

void first(int n){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < 2*n-2-2*i; j++){
			printf(" ");
		}
		for (int star = 0; star < 2*i+1; star++){
			printf("* ");
		}
		printf("\n");
	}
}

int main(int argc, char **argv){
	int n;

	if (argc != 2){
		printf("Incorrect number of arguments\n Must be one nonnegative integer\n");
		return 0;
	}

	char *str = argv[1];

	for (int symbol = 0; symbol < strlen(str); symbol++){
		if (str[symbol] < '0' || str[symbol] > '9'){
			printf("This is not a number or negative number\n");
			return 0;
		} 
	}

	sscanf(str, "%d", &n);

	first(n);
}
