.PHONY: clean

P = c_primes
OBJECTS =
CFLAGS = -g -Wall -pthread -O0 -std=gnu11
LDLIBS = -pthread
CC = clang

$(P): $(OBJECTS)

clean:
	rm -f $(P) *.o
	rm -rf $(P).dSYM
