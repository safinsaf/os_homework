#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define N 10
#define MB 1024 * 1024
int main(){
	for (int i = 0; i < N; i++){
		int *ptr;
		ptr = (int*) malloc(10 * MB);
		memset(ptr, 0, 10 * MB);
		sleep(1);
	}
}

/*
  PID USER      PR  NI    VIRT    RES    SHR S  %CPU %MEM     TIME+ COMMAND
  683 insaf     20   0   72004  61968    400 S   1.8  0.4   0:00.13 ex2
  684 insaf     20   0   17620   2040   1504 R   0.5  0.0   0:00.03 top
    1 root      20   0    8324    120     96 S   0.0  0.0   0:00.12 init
    3 root      20   0    8332     72     36 S   0.0  0.0   0:00.00 init
    4 insaf     20   0   16788   1608   1408 S   0.0  0.0   0:00.41 bash
  590 root      20   0    8332    160    124 S   0.0  0.0   0:00.00 init
  591 insaf     20   0   17052   3808   3696 S   0.0  0.0   0:00.44 bash
  682 insaf     20   0   16068   3008   1504 T   0.0  0.0   0:00.05 nano

  ex2 got some virt memory and memory
 */
