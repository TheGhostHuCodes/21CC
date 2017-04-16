#include <assert.h>

int main() {
    int list[100];
    int* list2 = list;

    *list2 = 7;

    assert(list[0] == 7);
}
