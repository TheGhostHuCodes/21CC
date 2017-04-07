#define skip_main
#include "../print_methods/print_methods.c"
#include "print_vtable.h"

static void song_print_html(textlist_s* in) {
    printf("<title>♫ %s ♫</title>\n", in->title);
    for (int i = 0; i < in->len; i++) {
        printf("%s<br>\n", in->items[i]);
    }
}

int main() {
    textlist_print_html(&save);
    printf("\n-----\n\n");

    print_hash_add(&save, song_print_html);
    textlist_print_html(&save);
}
