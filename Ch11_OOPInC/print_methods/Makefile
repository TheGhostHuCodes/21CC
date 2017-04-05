.PHONY: all clean

CFLAGS = -g -Wall -Werror -O0 -std=gnu11
LDLIBS =
CC = clang

all: print_methods print_dispatch

print_methods: print_methods.c
	$(CC) $(CFLAGS) print_methods.c -o $@

print_dispatch: print_dispatch.c
	$(CC) $(CFLAGS) print_dispatch.c -o $@

clean:
	rm -f print_methods print_dispatch
	rm -rf print_methods.dSYM print_dispatch.dSYM

