

#include <stdio.h>

int increment(int *x, int size);

int main() {
	static int arr[] = {2, 4, 6, 7};
	increment(arr, sizeof(arr)/sizeof(0));
}

int increment(int *x, int size) {
	printf("size: %d val: %d", size, *(x+size-1));
	return 0;
}