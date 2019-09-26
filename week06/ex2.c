#include <stdio.h>
#include <unistd.h>
#define N 1000

int main(){
	char s1[N] = "qwe";
	char s2[N]; 
	int p[2]; 
	pipe(p);
	write(p[1], s1, N); 
	if (fork() == 0){
		read(p[0], s2, N); 
		printf("%s\n", s2);
	}
}
