#define skip_main
#include "print_methods.c"

textlist_s recipe
    = {.title = "1 egg for baking",
       .len = 2,
       .items = (char* []){"1 Tbsp ground flax seeds", "3 Tbsp water"}};

void textlist_print(textlist_s* in) {
    if (in->print) {
        in->print(in);
        return;
    }

    printf("Title: %s\n\nItems:\n", in->title);
    for (int i = 0; i < in->len; ++i) {
        printf("\t%s\n", in->items[i]);
    }
}

int main() {
    textlist_print(&save);
    printf("\n-----\n\n");
    textlist_print(&recipe);
}
