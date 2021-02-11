
#include <stdio.h>

void printXTimes(int times) {
    if(times < 0) return;

    printXTimes(times-1);
    printf("%d%s", times, " ");
}


int main() {
    for(int i = 0; i < 10; i++) {
        printf("%d%s", i, " ");
    }
    printf("\n");

    int j = 0;
    while(j < 10) {
        printf("%d%s", j, " ");
        j++;
    }
    printf("\n");

    printXTimes(9);
    printf("\n");

    return 0;
}