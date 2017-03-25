#include <stdbool.h>
#include <strings.h>

bool check_name(const char** in) {
    return (!strcasecmp(in[0], "Iggy") && !strcasecmp(in[1], "Pop"))
           || (!strcasecmp(in[0], "James") && !strcasecmp(in[1], "Osterberg"));
}

int main(int argc, char** argv) {
    if (argc < 2) {
        return 0;
    }
    return check_name((const char**)&argv[1]);
}
