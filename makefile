all: pa1

clean:
	rm -f pa1 *.o

pa1: pa1.o main.o
	gcc pa1.o main.o -o pa1
pa1.o: pa1.c pa1.h
	gcc -c pa1.c
main.o: main.c pa1.h
	gcc -c main.c