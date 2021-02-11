#include <stdlib.h>
#include <stdio.h>

int main() {
	FILE* fpointer = fopen("output.txt", "a");
	fprintf(fpointer, "%s\n", "kiwi");
	fclose(fpointer);

	return 0;
}