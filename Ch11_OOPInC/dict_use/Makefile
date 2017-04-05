.PHONY: clean

P = dict_use
OBJECTS = keyval.o dict.o
CFLAGS = -g -Wall -Werror -O0 -std=gnu11
LDLIBS =
CC = clang

$(P): $(OBJECTS)

clean:
	rm -f $(P) *.o
	rm -rf $(P).dSYM

