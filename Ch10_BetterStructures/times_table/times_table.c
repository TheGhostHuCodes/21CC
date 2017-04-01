#include <math.h>
#include <stdio.h>

#define make_a_list(...)                                                       \
    (double[]) { __VA_ARGS__, NAN }

// list1 and list2 should be a list of doubles surrounded by parentheses,
// i.e. (1.1, 2.2, 3.3, 4.4) because the parentheses complete the macro
// expansion of make_a_list.
#define matrix_cross(list1, list2)                                             \
    matrix_cross_base(make_a_list list1, make_a_list list2)

void matrix_cross_base(double* list1, double* list2) {
    int count1 = 0;
    int count2 = 0;
    while (!isnan(list1[count1])) {
        ++count1;
    }
    while (!isnan(list2[count2])) {
        ++count2;
    }

    for (int i = 0; i < count1; ++i) {
        for (int j = 0; j < count2; ++j) {
            printf("%g\t", list1[i] * list2[j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

int main() {
    // The inner set of parentheses macro expand within the matrix_cross
    // macro to complete the make_a_list macro call.
    matrix_cross((1, 2, 4, 8), (5, 11.11, 15));
    matrix_cross((17, 19, 23), (1, 2, 3, 5, 7, 11, 13));
    matrix_cross((1, 2, 3, 5, 7, 11, 13), (1));
}
