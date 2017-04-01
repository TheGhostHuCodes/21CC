#include <math.h>
#include <stdio.h>
#include <strings.h>

typedef struct {
    double width;
    double height;
} size_s;

size_s width_height(char* papertype) {
    return !strcasecmp(papertype, "A4")
               ? (size_s){.width = 210, .height = 297}
               : !strcasecmp(papertype, "Letter")
                     ? (size_s){.width = 216, .height = 279}
                     : !strcasecmp(papertype, "Legal")
                           ? (size_s){.width = 216, .height = 356}
                           : (size_s){.width = NAN, .height = NAN};
}

int main() {
    size_s a4size = width_height("a4");
    printf("width=%g, height=%g\n", a4size.width, a4size.height);
}
