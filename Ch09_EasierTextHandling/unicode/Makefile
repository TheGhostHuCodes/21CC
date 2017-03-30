.PHONY: clean

P = unicode
OBJECTS = string_utilities.o
CFLAGS = `pkg-config --cflags glib-2.0` -g -Wall -O0 -std=gnu11
LDLIBS = `pkg-config --libs glib-2.0`
CC = clang

$(P): $(OBJECTS)

string_utilities.o : ../string_utilities/string_utilities.c
	$(CC) $(CFLAGS) ../string_utilities/string_utilities.c -c -o $@

clean:
	rm -f $(P) *.o uout.html
	rm -rf $(P).dSYM
