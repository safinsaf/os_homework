#include <stdio.h>
#include <stdlib.h>
#define buf_size 1000

char *LINE;

int read(){
	LINE = (char*) malloc(buf_size * sizeof(char));

	int pos = 0;

	char c;

	while (1){
		if (pos >= buf_size) return 1;
		c = getchar();
		if (c == '\n' || c == '\0'){
			LINE[pos] = '\0';
			return 0;
		}
		else{
			LINE[pos++] = c;
		}
	}
	return 0;
}

int execute(){
	if (system(LINE) != -1){
		return 0;
	}
	return 1;
}

int free1(){
	free(LINE);
}

int main(){
	while (1){
		if (read() == 0){
			if (execute() == 0){
				1;
			}
			else{
				printf("Incorrect command\n");
			}
			free1();
		}
		else{
			printf("Too long string\n");
		}
	}
}
