#include "unictr.h"
#include "../../Ch09_EasierTextHandling/string_utilities/string_utilities.h"
#include "../process_dir/process_dir.h"
#include <glib.h>
#include <stdlib.h>

typedef struct { int count; } count_s;

void hash_a_character(gunichar uc, GHashTable* hash) {
    count_s* ct = g_hash_table_lookup(hash, &uc);
    if (!ct) {
        ct = calloc(1, sizeof(count_s));
        gunichar* newchar = malloc(sizeof(gunichar));
        *newchar = uc;
        g_hash_table_insert(hash, newchar, ct);
    }
    ct->count++;
}

// Conforms to function signature of GHFunc.
void printone(void* key_in, void* val_in, void* ignored) {
    const gunichar* key = key_in;
    const count_s* val = val_in;
    char utf8[7];
    utf8[g_unichar_to_utf8(*key, utf8)] = '\0';
    printf("%s\t%i\n", utf8, val->count);
}

static gboolean equal_chars(const void* a_in, const void* b_in) {
    const gunichar* a = a_in;
    const gunichar* b = b_in;
    return (*a == *b);
}

GHashTable* new_unicode_counting_hash() {
    return g_hash_table_new(g_str_hash, equal_chars);
}
