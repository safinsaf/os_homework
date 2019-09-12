#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define buf_size 1000
int main(int argc, char **argv){
	
	int PID;
	
		char *arr[argc];
		arr[0] = (char *) malloc(buf_size);
		strcpy(arr[0], argv[1]);
		for (int i = 1; i < argc; i++){
			arr[i] = (char *) malloc(buf_size);
			int j;
			for(j = 0; j < buf_size && argv[i][j] != '\0'; j++){
				arr[i][j] = argv[i][j];
			}
			arr[i][j] = '\0';
		}
		execve(argv[1], argv, NULL);
		
	
}
