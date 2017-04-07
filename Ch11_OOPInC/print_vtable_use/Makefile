.PHONY: clean

P = print_vtable_use
OBJECTS = print_vtable.o
CFLAGS = `pkg-config --cflags glib-2.0` -g -Wall -Werror -O0 -std=gnu11
LDLIBS = `pkg-config --libs glib-2.0`
CC = clang

$(P): $(OBJECTS)

print_vtable.o : print_vtable.c
	$(CC) $(CFLAGS) print_vtable.c -c -o $@

clean:
	rm -f $(P) *.o
	rm -rf $(P).dSYM
