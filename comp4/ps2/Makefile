CC = g++
CFLAGS = -g -Og -Wall -ansi -pedantic -std=c++11
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

all: main.o Ptree.o
	$(CC) $^ -o $@ $(LIBS)

main.o: main.cpp Ptree.hpp
	$(CC) $(CFLAGS) -c $< -o $@

Ptree.o: Ptree.cpp Ptree.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm *.o all
