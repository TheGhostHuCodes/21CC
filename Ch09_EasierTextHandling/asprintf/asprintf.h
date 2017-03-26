#pragma once

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/* The declaration, to put into a .h file. The __attribute___ tells the
 * compiler to check printf-style type-compliance. It's not C-standard, but
 * a lot of compilers support it; just remove it if yours doesn't. */
int asprintf(char** str, char* fmt, ...) __attribute__((format(printf, 2, 3)));
