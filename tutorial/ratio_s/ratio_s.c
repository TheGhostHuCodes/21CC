#include <stdio.h>

typedef struct {
    int numerator;
    int denominator;
    double value;
} ratio_s;

ratio_s new_ratio(int numerator, int denominator) {
    return (ratio_s){.numerator = numerator,
                     .denominator = denominator,
                     .value = numerator / (double)denominator};
}

void print_ratio(ratio_s r) {
    printf("%i/%i = %g\n", r.numerator, r.denominator, r.value);
}

ratio_s ratio_add(ratio_s left, ratio_s right) {
    return (ratio_s){.numerator = left.numerator * right.denominator
                                  + right.numerator * left.denominator,
                     .denominator = left.denominator * right.denominator,
                     .value = left.value + right.value};
}

int main() {
    ratio_s two_thirds = new_ratio(2, 3);
    ratio_s a_quarter = new_ratio(1, 4);
    print_ratio(two_thirds);
    print_ratio(a_quarter);
    print_ratio(ratio_add(two_thirds, a_quarter));
}
