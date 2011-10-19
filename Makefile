CFLAGS=-g -Wall
CC=gcc

all: mathprep

mathprep: mathprep.o ui-cli.o
	$(CC) $(CFLAGS) -o mathprep mathprep.o ui-cli.o

mathprep.o: ui.h

clean:
	rm mathprep *.o
