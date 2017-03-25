#include <stdio.h>

int main() {
    int* var;
    const int** constptr = &var;
    const int fixed = 20;
    *constptr = &fixed;
    *var = 30;
    printf("fixed=%i *var=%i\n", fixed, *var);
}
