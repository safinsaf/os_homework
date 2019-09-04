#include <stdio.h>
void bubble_sort(int *arr, int n){
	for (int i = 0; i < n-1; i++){
		for (int j = 0; j < n-1; j++){
			if (arr[j] > arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}
int main(){
	int a[10] = {4,6,7,8,6,5,4,3,2,9};
	bubble_sort(a, 10);
	for (int i = 0; i < 10; i++){
		printf("%d ", a[i]);
	}
}
