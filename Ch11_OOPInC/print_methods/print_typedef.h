#pragma once

typedef struct textlist_s {
    char* title;
    char** items;
    int len;
    void (*print)(struct textlist_s*);
} textlist_s;
