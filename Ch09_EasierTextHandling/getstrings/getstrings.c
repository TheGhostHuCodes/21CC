#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

void get_strings(const char* in) {
    char* cmd;
    asprintf(&cmd, "strings %s", in);
    if (system(cmd)) {
        fprintf(stderr, "something went wrong when running %s.\n", cmd);
    }
    free(cmd);
}

int main(int argc, char** argv) { get_strings(argv[0]); }
