#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#ifdef _WIN32
#include <Windows.h>
#endif

#define SIZE 10

int stack[SIZE];
int cur;
int var;

int sleep1;
int sleep2;
int wakeup1;
int wakeup2;

void *consumer(){
	while (1){
		if (cur > 0){
			cur = cur - 1;
		}
		else if (cur == 0){
			sleep2 = 1;
		}
		
		if(sleep1 && cur == 0){
			wakeup1 = 1;
		}

		while (sleep2){
			if (wakeup2){
				wakeup2 = 0;
				sleep2 = 0;
				break;
			}
		}

	}
}

void *producer(){
	while (1){
		if (cur < SIZE){
			cur = cur + 1;
		}
		else if (cur == SIZE){
			sleep1 = 1;
		}

		if (sleep2 && cur == SIZE){
			wakeup2 = 1;
		}
		

		while (sleep1){
			if (wakeup1){
				wakeup1 = 0;
				sleep1 = 0;
				break;
			}
		}
	}
}

int main(){
	int rc;
	pthread_t t1, t2;
	rc = pthread_create(&t1, NULL, (void*)producer, NULL);
	//pthread_join(t1, NULL);
	rc = pthread_create(&t2, NULL, (void*)consumer, NULL);
	//pthread_join(t2, NULL);

	while (1){
		printf(" Cur : %d \n", cur);
		printf(" sleep1 : %d \n", sleep1);
		printf(" sleep2 : %d \n", sleep2);
		printf(" wakeup1 : %d \n", wakeup1);
		printf(" wakeup2 : %d \n\n", wakeup2);
		sleep (0.1);
	}
}




/*
After some time both threads start to sleep
*/
