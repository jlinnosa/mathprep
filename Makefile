CFLAGS=-g -Wall
CC=gcc

all: mathprep

mathprep: mathprep.o
	$(CC) $(CFLAGS) -o mathprep mathprep.o

clean:
	rm mathprep *.o
