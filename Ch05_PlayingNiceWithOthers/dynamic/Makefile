.PHONY: clean

P = dynamic
OBJECTS =
CFLAGS = -I/usr/local/opt/readline/include -g -Wall -Werror -O3
LDLIBS = -L/usr/local/opt/readline/lib -lreadline -ldl
CC = clang

$(P): $(OBJECTS)

clean:
	rm -f $(P) *.o
	rm -f fn.*
	rm -rf $(P).dSYM
