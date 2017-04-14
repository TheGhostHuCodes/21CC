.PHONY: clean

P = openmp_mutexes
OBJECTS =
CFLAGS = `pkg-config --cflags glib-2.0` -g -Wall -fopenmp -O0 -std=gnu11
LDLIBS = `pkg-config --libs glib-2.0` -fopenmp
CC = gcc

$(P): $(OBJECTS)

clean:
	rm -f $(P) *.o
	rm -rf $(P).dSYM
