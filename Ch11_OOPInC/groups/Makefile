.PHONY: clean

P = groupabm
OBJECTS = groups.o
CFLAGS = -I/usr/local/Cellar/apophenia/1.0_1/include `pkg-config --cflags glib-2.0 gsl` -g -Wall -Werror -O3
LDLIBS = -L/usr/local/Cellar/apophenia/1.0_1/lib -lapophenia `pkg-config --libs glib-2.0 gsl`
CC = clang

$(P): $(OBJECTS)

clean:
	rm -f $(P) *.o
	rm -rf $(P).dSYM
