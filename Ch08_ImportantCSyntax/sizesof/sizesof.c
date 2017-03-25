#include <stdio.h>

#define Peval(cmd) printf(#cmd ": %g\n", cmd);

int main() {
    double* plist = (double[]){1, 2, 3};
    double list[] = {1, 2, 3};
    Peval(sizeof(plist) / (double)sizeof(double));
    Peval(sizeof(list) / (double)sizeof(double));
}
