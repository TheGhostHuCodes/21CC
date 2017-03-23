.PHONY: clean

P = dict_test
OBJECTS = dict.o keyval.o
CFLAGS = `pkg-config --cflags glib-2.0` -g -Wall -O0 -std=gnu11
LDLIBS = `pkg-config --libs glib-2.0`
CC = clang

$(P): $(OBJECTS)

dict.o : ../../Ch11_OOPInC/dict_use/dict.c
	$(CC) $(CFLAGS) ../../Ch11_OOPInC/dict_use/dict.c -c -o $@

keyval.o : ../../Ch11_OOPInC/dict_use/keyval.c
	$(CC) $(CFLAGS) ../../Ch11_OOPInC/dict_use/keyval.c -c -o $@

clean:
	rm -f $(P) *.o
	rm -rf $(P).dSYM
