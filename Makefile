CFLAGS=-g -Wall
CC=gcc

all: mathprep

mathprep: mathprep.o ui-cli.o tools.o
	$(CC) $(CFLAGS) -o mathprep mathprep.o ui-cli.o tools.o

mathprep.o: ui.h tools.h

clean:
	rm -f -- mathprep *.o *~

indent:
	indent -kr -i8 *.c *.h
