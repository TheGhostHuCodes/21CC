#include "keyval.h"

// value to return from dictionary_find if a key is not found. This is
// returned instead of NULL because NULL could be a valid value in a
// key-value pair.
extern void* dictionary_not_found;

typedef struct dictionary {
    keyval** pairs;
    int length;
} dictionary;

dictionary* dictionary_new(void);
dictionary* dictionary_copy(dictionary* in);
void dictionary_free(dictionary* in);
void dictionary_add(dictionary* in, char* key, void* value);
void* dictionary_find(const dictionary* in, const char* key);
