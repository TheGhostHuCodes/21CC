#include <stdio.h>

void loops(int max) {
    int i = 0;
    do {
        printf("Hello #%i\n", i);
        i++;
    } while (i < max);
}

int main() {
    loops(3);
    loops(0);
}
