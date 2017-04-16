.PHONY: clean

P = nyt_feed
OBJECTS =
CFLAGS = -I/usr/local/opt/libxml2/include/libxml2 `curl-config --cflags` -g -Wall -Werror -O3
LDLIBS = `curl-config --libs` -lxml2 -lpthread
CC = clang

$(P): $(OBJECTS)

docs:
	doxygen

clean:
	rm -f $(P) *.o now.html nytimes_feeds.rss
	rm -rf $(P).dSYM html latex
