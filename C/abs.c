#include <stdio.h>

#define ABS(x) ((x >= 0) * x + (x <= 0) *-x)

int main() {
	printf("Absolute value of -5: %d\n", ABS(-5));
	printf("Absolute value of 5: %d\n", ABS(5));
	printf("Absolute value of 0: %d\n", ABS(0));
	printf("Absolute value of -32: %d\n", ABS(-32));
}