.PHONY: clean

P = regex_fns
OBJECTS =
CFLAGS = -g -Wall -O0 -std=gnu11 -Dtest_regexes
LDLIBS =
CC = clang

$(P): $(OBJECTS)

clean:
	rm -f $(P) *.o
	rm -rf $(P).dSYM
