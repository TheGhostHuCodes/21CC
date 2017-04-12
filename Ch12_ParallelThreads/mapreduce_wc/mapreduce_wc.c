#include "../../Ch07_InessentialCSyntax/strtod/stopif.h"
#include "../wordcount/wordcount.c"

int main(int argc, char** argv) {
    argc--;
    argv++;
    Stopif(!argc, return 0, "Please give some file names on the command line.");
    long int total_wc = 0;

#pragma omp parallel for reduction(+ : total_wc)
    for (int i = 0; i < argc; ++i) {
        long int this_count = wc(argv[i]);
        total_wc += this_count;
        printf("%s:\t%ld\n", argv[i], this_count);
    }

    printf("Σ:\t%li\n", total_wc);
}
