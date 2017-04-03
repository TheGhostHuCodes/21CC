/** \file show_tree.c
 *  \brief Program to display a tree representation of a directory.
 */
#include "process_dir.h"
#include <stdio.h>

void print_dir(filestruct in) {
    for (int i = 0; i < in.depth - 1; ++i) {
        printf("    ");
    }
    printf("├ %s\n", in.name);
    for (int i = 0; i < in.depth - 1; ++i) {
        printf("    ");
    }
    printf("└───┐\n");
}

void print_file(filestruct in) {
    for (int i = 0; i < in.depth; ++i) {
        printf("    ");
    }
    printf("| %s\n", in.name);
}

int main(int argc, char** argv) {
    char* start = (argc > 1) ? argv[1] : ".";
    printf("Tree for %s:\n", start ? start : "the current directory");
    process_dir(.name = start, .file_action = print_file,
                .directory_action = print_dir);
}
