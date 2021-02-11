#include <stdio.h>
#include <stdlib.h>

void swap(int *i, int *j);
void bubblesort(int arr[], int size);
void printArr(int arr[], int size);

int main() {
	int arr[] = {10, 2, 4, 12, 17, 18, 19, 6, 7, 9};
	printArr(arr, sizeof(arr)/ sizeof(arr[0]));
	bubblesort(arr, sizeof(arr)/ sizeof(arr[0]));
	printArr(arr, sizeof(arr)/ sizeof(arr[0]));
	return 0;
}

void bubblesort(int arr[], int size) {
	int swapped = 0;

	int *idx = arr;

	do {
		swapped = 0;
		for(int i = 0; i < size - 1; i++) {
			if (*(idx+i) > *(idx+i+1)) {
				 swap(idx+i, idx+i+1);
				 swapped = 1;
			}
		}
	} while(swapped);

}

void printArr(int arr[], int size) {
	int *idx = arr;
	for(int i = 0; i < size; i++) printf("%d, ", *(idx+i));
	printf("\n");
}

void swap(int *i, int *j) {
	int temp = *i;
	*i = *j;
	*j = temp;
}