#Makefile for inventory database.

CC = gcc
CFLAGS = -Wall -std=c99 -ggdb
LINKFLAGS = -I/usr/local/Cellar/cunit/2.1-2/include/ -L/usr/local/lib

all: lager main

lager:
	$(CC) $(CFLAGS) lager.c -c

main: lager
	$(CC) $(CFLAGS) main.c lager.o -o main

test: lager
	$(CC) $(LINKFLAGS) test1.c -o test -lm -lcunit

test2: lager
	$(CC) $(LINKFLAGS) newcunittest.c -o test2 -lm -lcunit

.PHONY: clean

clean: 
	rm -f *.o

run_test: test
	./test

run: main
	./main
