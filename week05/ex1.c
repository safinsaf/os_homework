#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_THREADS 10

void *print(int i){
	printf("Hello from thread %lu - I was created at iteration %d \n",  pthread_self(), i);
	pthread_exit(NULL);
}

int main(){
	int rc;
	pthread_t t;


	for (int i = 0; i < NUM_THREADS; i++){
		rc = pthread_create(&t, NULL, (void*)print, (void*) i);
		pthread_join(t, NULL);

		if (rc) {
 			printf("\n ERROR: return code from pthread_create is %d \n", rc);
			exit(1);
		}

		printf(" I am thread %lu. Created new thread (%lu) in iteration %d ...\n\n", pthread_self(),  t, i);

	}

	pthread_exit(NULL);
}


/*
When I dont use pthread_join output is messy, threads print messages
without any order
Also, threads have different id`s

When I use pthread_join output is ordered
Threads have the same id, because in linux threads are reused if possible
In this case it is possible, because previous thread stops before current start to run
*/
