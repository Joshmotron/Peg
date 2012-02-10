CC=g++
CFLAGS=-c -Wall

all: a.exe

a.exe: testpeg.o peg.o
	$(CC) testpeg.o peg.o -o a.exe
	
peg.o: peg.cpp peg.h
	$(CC) $(CFLAGS) peg.cpp
	
testpeg.o: testpeg.cpp peg.h
	$(CC) $(CFLAGS) testpeg.cpp
	
clean:
	rm -rf *.o