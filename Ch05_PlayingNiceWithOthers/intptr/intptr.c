#include <stdint.h>
#include <stdio.h>

int main() {
    char* astring = "I am somewhere in memory.";
    intptr_t location = (intptr_t)astring;
    printf("%s\n", (char*)location);
}

