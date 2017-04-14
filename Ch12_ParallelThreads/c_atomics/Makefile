.PHONY: clean

P = c_factors
OBJECTS =
CFLAGS = -g -Wall -pthread -O0 -std=gnu11
LDLIBS = -pthread
CC = gcc

$(P): $(OBJECTS)

clean:
	rm -f $(P) *.o
	rm -rf $(P).dSYM
