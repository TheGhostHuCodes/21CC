#include <stdio.h>
#include <stdlib.h>

void double_in(int* in) { *in *= 2; }

int main() {
    int x = 10;
    double_in(&x);
    printf("x is now %i.\n", x);
}
