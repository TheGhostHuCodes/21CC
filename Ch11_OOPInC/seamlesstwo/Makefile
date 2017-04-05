.PHONY: clean

P = seamlesstwo
OBJECTS =
CFLAGS = -g -Wall -Werror -Wno-microsoft-anon-tag -O0 -std=gnu11 -fms-extensions
LDLIBS = -lm
CC = clang

$(P): $(OBJECTS)

clean:
	rm -f $(P) *.o
	rm -rf $(P).dSYM

