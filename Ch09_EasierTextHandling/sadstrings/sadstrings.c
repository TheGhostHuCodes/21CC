#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_strings(const char* in) {
    char* cmd;
    int len = strlen("strings ") + strlen(in) + 1;
    cmd = malloc(len);
    snprintf(cmd, len, "strings %s", in);
    if (system(cmd)) {
        fprintf(stderr, "something went wrong running %s.\n", cmd);
    }
    free(cmd);
}

int main(int argc, char** argv) { get_strings(argv[0]); }
