#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int random(int min, int max) {
    srand((unsigned int)time(NULL));
    return rand() % max + min;
}

int main(void) {
    printf("%d\n", random(1, 100));
    return 0;
}