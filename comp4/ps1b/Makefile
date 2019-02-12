CC = g++
CFLAGS = -g -Og -Wall -ansi -pedantic -std=c++11
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

all: PhotoMagic

PhotoMagic: PhotoMagic.o LFSR.o
	$(CC) $^ -o $@ $(LIBS)

PhotoMagic.o: PhotoMagic.cpp LFSR.hpp
	$(CC) $(CFLAGS) -c $< -o $@

LFSR.o: LFSR.cpp LFSR.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm *.o PhotoMagic
