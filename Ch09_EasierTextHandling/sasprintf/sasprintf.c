#include "../asprintf/asprintf.h"
#include <stdio.h>
#include <stdlib.h>

#define Sasprintf(write_to, ...)                                               \
    {                                                                          \
        char* temp_string_for_extending = (write_to);                          \
        asprintf(&(write_to), __VA_ARGS__);                                    \
        free(temp_string_for_extending);                                       \
    }

int main() {
    int i = 3;
    char* q = NULL;
    Sasprintf(q, "SELECT * FROM tab");
    Sasprintf(q, "%s WHERE col%i IS NOT NULL", q, i);
    printf("%s\n", q);
}
