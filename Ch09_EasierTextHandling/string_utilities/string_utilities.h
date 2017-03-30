#include <string.h>
#define _GNU_SOURCE
#include <stdio.h>

#define Sasprintf(write_to, ...)                                               \
    {                                                                          \
        char* tmp_string_for_extending = write_to;                             \
        asprintf(&(write_to), __VA_ARGS);                                      \
        free(tmp_string_for_extending);                                        \
    }

char* string_from_file(const char* filename);

typedef struct ok_array {
    char** elements;
    char* base_string;
    int length;
} ok_array;

ok_array* ok_array_new(char* instring, const char* delimiters);

void ok_array_free(ok_array* ok_in);
