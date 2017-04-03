.PHONY: clean docs

P = amort_use
OBJECTS = amort_interface.o amortize.o
CFLAGS = -g -Wall -Werror -Wno-initializer-overrides -O0 -std=gnu11
LDLIBS = -lm
CC = clang

$(P): $(OBJECTS)

docs: 
	doxygen

clean:
	rm -f $(P) *.o
	rm -rf $(P).dSYM html latex

