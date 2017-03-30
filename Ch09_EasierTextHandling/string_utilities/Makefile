.PHONY: clean lib test

P = string_utilities
OBJECTS =
CFLAGS = `pkg-config --cflags glib-2.0` -g -Wall -O0 -std=gnu11
LDLIBS = `pkg-config --libs glib-2.0`
CC = clang

test: CFLAGS += -Dtest_ok_array

test: string_utilities
	./string_utilities

lib: $(P).o

clean:
	rm -f $(P) *.o
	rm -rf *.dSYM
