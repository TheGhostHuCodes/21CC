#include "keyval.h"
#include <stdlib.h>
#include <strings.h>

keyval* keyval_new(char* key, void* value) {
    keyval* out = malloc(sizeof(keyval));
    *out = (keyval){.key = key, .value = value};
    return out;
}

/** Copy a key/value pair. The new pair has pointers to the values in the old
 * pair, not copies of their data. */
keyval* keyval_copy(const keyval* in) {
    keyval* out = malloc(sizeof(keyval));
    *out = *in;
    return out;
}

void keyval_free(keyval* in) { free(in); }

int keyval_matches(const keyval* in, const char* key) {
    return !strcasecmp(in->key, key);
}
