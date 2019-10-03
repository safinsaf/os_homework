#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *realloc1(void *ptr, size_t size){
	if (ptr == NULL){
		if (size == 0) return NULL;
		return malloc(size);	
	}
	if (size == 0) {
		free(ptr);
		return NULL;
	}

	void * new = malloc(size);
	int minsize = size; 
	if (minsize > ((size_t*)(ptr))[-1]) minsize = ((size_t*)(ptr))[-1];
	memcpy (new, ptr, minsize);
	free(ptr);
	
	return new;
}

int main(){

	printf("Enter original array size:");
	int n1=0;
	scanf("%d",&n1);

	int* a1 = calloc (sizeof(int), n1);
	int i;
	for(i=0; i<n1; i++){
		a1[i]=100;
		printf("%d ",a1[i] );
	}

	printf("\nEnter new array size: ");
	int n2=0;
	scanf("%d",&n2);

	a1 = realloc1(a1, n2 * sizeof(int));
	
	
	for(i=0; i<n2;i++){
		printf("%d ",a1[i]);
	}
	printf("\n");}
