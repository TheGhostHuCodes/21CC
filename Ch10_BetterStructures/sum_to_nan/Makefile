.PHONY: clean

P = sum_to_nan
OBJECTS =
CFLAGS = -g -Wall -Werror -O0 -std=gnu11
LDLIBS = -lm
CC = clang

$(P): $(OBJECTS)

clean:
	rm -f $(P) *.o
	rm -rf $(P).dSYM
