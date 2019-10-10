#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

#define N 10
#define MB 1024 * 1024
int main(){
	for (int i = 0; i < N; i++){
		int *ptr;
		ptr = (int*) malloc(10 * MB);
		memset(ptr, 0, 10 * MB);
		struct rusage buf; 
    	getrusage(RUSAGE_SELF, &buf); 
    	printf("maximum resident set size: %ld\n", buf.ru_maxrss); 
    	printf("integral shared memory size: %ld\n", buf.ru_ixrss); 
		sleep(1);
	}
}

