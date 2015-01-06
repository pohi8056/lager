#Makefile for inventory database.

CC = gcc
CFLAGS = -Wall -std=c99 -ggdb
LINKFLAGS = -I/usr/local/Cellar/cunit/2.1-2/include/ -L/usr/local/lib

all: lager main

lager:
	$(CC) $(CFLAGS) lager.c -c

main: lager
	$(CC) $(CFLAGS) main.c lager.o -o main

test1: lager
	$(CC) $(LINKFLAGS) test1.c -o test1 -lm -lcunit

test2: lager
	$(CC) $(LINKFLAGS) newcunittest.c -o test2 -lm -lcunit

.PHONY: clean

clean: 
	rm -f *.o

run_test1: test1
	./test1

run_test2: test2
	./test2 < input.txt

run: main
	./main
