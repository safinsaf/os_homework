#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define N 20
int main(){
	int a = open("/dev/random", O_RDONLY);

	char temp[N];
	int b = read(a, temp, N);
	for (int i = 0; i < N; i++){
		printf("%c", (temp[i]+1000)%70 + 32);
	}
	printf("\n");
}
