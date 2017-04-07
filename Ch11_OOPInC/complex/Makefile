.PHONY: clean

P = simple_cplx
OBJECTS = cplx.o
CFLAGS = `pkg-config --cflags gsl` -g -Wall -Werror -O3
LDLIBS = `pkg-config --libs gsl`
CC = clang

$(P): $(OBJECTS)

clean:
	rm -f $(P) *.o
	rm -rf $(P).dSYM
