#include <stdio.h>

void bubble_sort(int *arr, int len){
	for(int i = 0; i < len; ++i){
		for(int j = 0; j < len - i - 1; ++j){
			if(arr[j] > arr[j + 1]){
				int tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp; 
			}		
		}	
	}
}

int main(){
	int n;
	scanf("%d", &n);
	int a[(const int)(n)];	
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);	
	}
	bubble_sort(a, n);
	for(int i = 0; i < n; ++i)
		printf("%d ", a[i]);	
	return 0;
}
