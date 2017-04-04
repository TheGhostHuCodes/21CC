.PHONY: clean docs

P = charct
OBJECTS = unictr.o process_dir.o string_utilities.o
CFLAGS = `pkg-config --cflags glib-2.0` -g -Wall -Werror -O0 -std=gnu11
LDLIBS = `pkg-config --libs glib-2.0`
CC = clang

$(P): $(OBJECTS)

process_dir.o: ../process_dir/process_dir.c
	$(CC) $(CFLAGS) ../process_dir/process_dir.c -c -o $@

string_utilities.o : ../../Ch09_EasierTextHandling/string_utilities/string_utilities.c
	$(CC) $(CFLAGS) ../../Ch09_EasierTextHandling/string_utilities/string_utilities.c -c -o $@

clean:
	rm -f $(P) *.o
	rm -rf $(P).dSYM html latex

