#include <math.h>
#include <stdio.h>

typedef struct point {
    double x;
    double y;
} point;

typedef struct {
    union {
        struct point;
        point p2;
    };
    double z;
} threepoint;

double length(point p) { return sqrt(p.x * p.x + p.y * p.y); }

double threelength(threepoint p) {
    return sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
}

int main() {
    threepoint p = {.x = 3, .y = 0, .z = 4};
    printf("p is %g units from the origin\n", threelength(p));
    double xylength = length(p.p2);
    printf("Its projection onto the XY plane is %g units from the origin\n",
           xylength);
}
