.PHONY: clean

P = pthread_factors
OBJECTS =
CFLAGS = -g -Wall -fopenmp -O0 -std=gnu11
LDLIBS = -fopenmp
CC = gcc

$(P): $(OBJECTS)

clean:
	rm -f $(P) *.o xpt
	rm -rf $(P).dSYM
