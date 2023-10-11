#Macros
CC= gcc
CFLAGS= -Wall -c

all: pa1

clean:
	rm -f pa1 *.o

pa1: pa1.o main.o
	$(CC) -Wall -g $< main.o -o $@
pa1.o: pa1.c pa1.h
	$(CC) $(CFLAGS) $<
main.o: main.c pa1.h
	$(CC) $(CFLAGS) $<