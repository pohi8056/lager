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
	$(CC) $(LINKFLAGS) newcunittest.c -o test -lm -lcunit

testp: lager
	$(CC) newcunittest.c -o testp -lm -lcunit

.PHONY: clean

clean: 
	rm -f *.o

lager_cov:
	$(CC) -fprofile-arcs -ftest-coverage lager.c -c

cov: lager_cov
	$(CC) $(LINKFLAGS) -fprofile-arcs -ftest-coverage newcunittest.c -o cov -lm -lcunit

run_cov: test
	./test < input.txt

run_test: test
	./test < input.txt

run_testp: testp
	./testp < input.txt

run: main
	./main

val: test
	valgrind --leak-check=yes test