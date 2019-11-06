#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#define BUF_SIZE 10000


int main(int argc, char *argv[]){
	char inp[BUF_SIZE];
	int append = 0;

	if (strcmp(argv[1], "-a") == 0){
		append = 1;
	}

	FILE *fp[argc - append - 1];

	if (append){
		for (int i = 0; i < argc - 1 - append; i++){
			fp[i] = fopen(argv[i + 1 + append], "a");
		}
	}
	else{
		for (int i = 0; i < argc - 1; i++){
			fp[i] = fopen(argv[i + 1], "w");
		}
	}

	while (1){
		int err = read(0,inp,BUF_SIZE);
		if (err <= 0) break;

		for (int i = 0; i < argc-append; i++){
			fprintf(fp[i], "%s\n", inp);
		}
		printf("%s\n", inp);
	}
	
}
