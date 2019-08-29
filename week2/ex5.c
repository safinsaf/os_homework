#include <stdio.h>
#include <string.h>

//Command line arguments: size_of_picture number_of_picture
//size_of_picture can be any nonnegative number
//number_of_picture must be in diaposone [1;4]



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

void second(int n){
	for (int i = 0; i < n; i++){
		for (int j = 0; j <= i; j++){
			printf("*");
		}
		printf("\n");
	}
}

void third(int n){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < (i<n/2?i+1:n-i) ; j++){
			printf("*");
		}
		printf("\n");
	}
}

void fourth(int n){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			printf("*");
		}
		printf("\n");
	}
}

int main(int argc, char **argv){
	int n;
	int shape;

	if (argc != 3){
		printf("Incorrect number of arguments\n Must be two nonnegative integers, second should be in diaposone [1,4]\n");
		return 0;
	}

	char *str = argv[1];

	for (int symbol = 0; symbol < strlen(str); symbol++){
		if (str[symbol] < '0' || str[symbol] > '9'){
			printf("First argument is (not a number) or negative number\n");
			return 0;
		} 
	}

	str = argv[2];

	for (int symbol = 0; symbol < strlen(str); symbol++){
		if (str[symbol] < '0' || str[symbol] > '9'){
			printf("Second argument is (not a number) or negative number\n");
			return 0;
		} 
	}

	sscanf(argv[1], "%d", &n);
	sscanf(argv[2], "%d", &shape);

	if (shape < 1 || shape > 4){
		printf("Second argument should be in [1,4] diaposone");
	}
	else if (shape == 1){
		first(n);
	}
	else if (shape == 2){
		second(n);
	}
	else if (shape == 3){
		third(n);
	}
	else if (shape == 4){
		fourth(n);
	}

}
