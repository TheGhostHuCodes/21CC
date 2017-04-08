#include <glib.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char* data;
    size_t start;
    size_t end;
    int* refs;
} fstr_s;

fstr_s* fstr_new(const char* filename);
fstr_s* fstr_copy(const fstr_s* in, size_t start, size_t len);
void fstr_show(const fstr_s* fstr);
void fstr_free(fstr_s* in);

typedef struct {
    fstr_s** strings;
    int count;
} fstr_list;

fstr_list fstr_split(const fstr_s* in, const gchar* start_pattern);
void fstr_list_free(fstr_list in);
