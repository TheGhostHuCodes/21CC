.PHONY: clean

P = cetology
OBJECTS = fstr.o string_utilities.o
CFLAGS = `pkg-config --cflags glib-2.0` -g -Wall -Werror -O3
LDLIBS = `pkg-config --libs glib-2.0`
CC = clang

$(P): $(OBJECTS)

string_utilities.o: ../../Ch09_EasierTextHandling/string_utilities/string_utilities.c
	$(CC) $(CFLAGS) ../../Ch09_EasierTextHandling/string_utilities/string_utilities.c -c -o $@

moby:
	./find.moby

clean:
	rm -f $(P) *.o
	rm -rf $(P).dSYM
