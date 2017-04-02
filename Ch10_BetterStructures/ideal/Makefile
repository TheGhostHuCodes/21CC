.PHONY: clean

P = ideal
OBJECTS =
CFLAGS = -g -Wall -Werror -Wno-initializer-overrides -O0 -std=gnu11
LDLIBS =
CC = clang

$(P): $(OBJECTS)

clean:
	rm -f $(P) *.o
	rm -rf $(P).dSYM
