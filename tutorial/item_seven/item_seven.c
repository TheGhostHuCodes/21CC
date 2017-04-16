#include <stdio.h>

int int_list[10];

int main() {
    int len = 20;
    char string[len];

    int_list[7] = 7;
    snprintf(string, len, "Item seven is %i.", int_list[7]);
    printf("string says; <<%s>>\n", string);
}
