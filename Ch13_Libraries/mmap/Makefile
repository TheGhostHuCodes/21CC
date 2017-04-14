.PHONY: clean

P = mmap
OBJECTS =
CFLAGS = -g -Wall -O0 -std=gnu11
LDLIBS =
CC = clang

$(P): $(OBJECTS)

clean:
	rm -f $(P) *.o mmapped.bin
	rm -rf $(P).dSYM
