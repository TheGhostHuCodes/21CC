#include <assert.h>
#include <stdlib.h>

typedef struct {
    int* counter1;
    int* counter2;
} counter_s;

void check_counter(int* ctr) { assert(*ctr != 0); }

double ratio(const counter_s* in) {
    check_counter(in->counter2);
    return *in->counter1 / (double)(*in->counter2);
}

int main() {
    counter_s cc = {.counter1 = malloc(sizeof(int)),
                    .counter2 = malloc(sizeof(int))};
    *cc.counter1 = *cc.counter2 = 1;
    ratio(&cc);
}
