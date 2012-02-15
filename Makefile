CC=g++
CFLAGS=-c -Wall

all: a.exe

a.exe: tp.o peg.o
	$(CC) tp.o peg.o -o a.exe
	
peg.o: peg.cpp peg.h
	$(CC) $(CFLAGS) peg.cpp
	
tp.o: tp.cpp peg.h
	$(CC) $(CFLAGS) tp.cpp
	
clean:
	rm -rf *.o
