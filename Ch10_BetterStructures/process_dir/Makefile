.PHONY: clean docs

P = show_tree
OBJECTS = process_dir.o
CFLAGS = -g -Wall -Werror -O0 -std=gnu11
LDLIBS =
CC = clang

$(P): $(OBJECTS)

docs: 
	doxygen

clean:
	rm -f $(P) *.o
	rm -rf $(P).dSYM html latex

