#define _GNU_SOURCE
#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int system_w_printf(const char* fmt, ...) __attribute__((format(printf, 1, 2)));

int system_w_printf(const char* fmt, ...) {
    char* cmd;
    va_list argp;
    va_start(argp, fmt);
    vasprintf(&cmd, fmt, argp);
    va_end(argp);
    int out = system(cmd);
    free(cmd);
    return out;
}

int main(int argc, char** argv) {
    assert(argc == 2);
    return system_w_printf("ls %s", argv[1]);
}
