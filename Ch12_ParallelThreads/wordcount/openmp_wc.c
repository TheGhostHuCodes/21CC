#include "../../Ch07_InessentialCSyntax/strtod/stopif.h"
#include "wordcount.c"

int main(int argc, char** argv) {
    argc--;
    argv++;
    Stopif(!argc, return 0, "Please give some file names on the command line.");
    int count[argc];

#pragma omp parallel for
    for (int i = 0; i < argc; ++i) {
        count[i] = wc(argv[i]);
        printf("%s:\t%i\n", argv[i], count[i]);
    }

    long int sum = 0;
    for (int i = 0; i < argc; ++i) {
        sum += count[i];
    }
    printf("Σ:\t%li\n", sum);
}
