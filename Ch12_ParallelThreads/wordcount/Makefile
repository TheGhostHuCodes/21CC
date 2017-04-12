.PHONY: clean

P = openmp_wc
OBJECTS = string_utilities.o
CFLAGS = `pkg-config --cflags glib-2.0` -g -Wall -fopenmp=libgomp -O0 -std=gnu11
LDLIBS = `pkg-config --libs glib-2.0` -fopenmp
CC = clang

$(P): $(OBJECTS)

string_utilities.o : ../../Ch09_EasierTextHandling/string_utilities/string_utilities.c
	$(CC) $(CFLAGS) ../../Ch09_EasierTextHandling/string_utilities/string_utilities.c -c -o $@

clean:
	rm -f $(P) *.o
	rm -rf $(P).dSYM
