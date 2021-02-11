#include <stdio.h>

int writeToFile(char* filename, char* toWrite);

int main() {

    char cur = 'y';
    char filename[100];
    char content[255];

    while (cur != 'n') {
        printf("%s", "Where do you want to save you file work?: ");
        scanf("%s", filename);

        printf("%s","Type in you content:\n");
        scanf("%\n]");
        scanf("%[^\n]", content);

        writeToFile(filename, content);

        printf("%s", "Do you want to continue? (Type in \"n\" to stop):");
        scanf("%s", &cur);
        printf("\n");
        scanf("[\n]");
    }

    return 0;
}

int writeToFile(char* filename, char* toWrite) {
    FILE* fpointer = fopen(filename, "a");
    fprintf(fpointer, "%s\n", toWrite);
    fclose(fpointer);
    return 0;
}
