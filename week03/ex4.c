#include <stdio.h>
void quick_sort(int *arr, int l, int r){
	int i = 0;

	if (l<r){
		int pivot = arr[r];
		i = l;
		for (int j = l; j <= r; j++){
			if (arr[j] < pivot){
				int temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
				i=i+1;
			}
		}
		int temp = arr[i];
		arr[i] = arr[r];
		arr[r] = temp;
		quick_sort(arr, l, i-1);
		quick_sort(arr, i+1, r);
	}
	
}

int main(){
	int a[10] = {4,6,7,8,6,5,4,3,2,9};
	quick_sort(a, 0, 9);
	for (int i = 0; i < 10; i++){
		printf("%d ", a[i]);
	}
}
