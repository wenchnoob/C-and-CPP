
#include <stdio.h>

int* partition(int *arr, int size);
void swap(int *val1, int *val2);

int main() {
	int arr[] = {5, 6, 9, 4, 5, 6, 7, 8, 9, 10};
	partition(arr, sizeof(arr)/sizeof(0));
}

int* partition(int *arr, int size) {
	int pivot = *(arr+size);
	int *beforePivot = arr;

	int *i = arr;
	for(; i < (arr + size - 1); i++) {
		if(*beforePivot < pivot) swap(beforePivot++, i);
	}

	printf("%u %u \n", arr, beforePivot);
	swap(beforePivot++, i);

	for(int j = 0; j < size; j++) {
		printf("%d, ", *(arr+j));
	}

	return beforePivot;
}

void swap(int *val1, int *val2) {
	int temp = *val1;
	*val1 = *val2;
	*val2 = temp;
}