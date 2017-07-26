CC = gcc

CFLAGS = -g

INCLUDES = -I/usr/local/include -I /usr/include

LFLAGS = -L/usr/lib  -L/usr/local/lib

LIBS = -ljson-c -lcurl

SRCS = client/dict.c client/json.c client/parser.c client/request.c client/util.c

OBJS = $(SRCS:.c=.o)

MAIN = dict

.PHONY: depend clean

TARGET = main

all: $(MAIN)
		@echo  Dict has been compiled

$(MAIN): $(OBJS)
		$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

.c.o:
		$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
		$(RM) client/*.o *~ $(MAIN)

depend: $(SRCS)
		makedepend $(INCLUDES) $^