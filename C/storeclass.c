
#include <stdio.h>
#include <stdlib.h>

#define SQUARE(x) (x*x)

int increment();

int main() {

	for(register int i = 0; i < 10; i = increment()) printf("Cur val: %d\n", SQUARE(i));

}

int increment() {
	static int x = 1;
	return x++;
}