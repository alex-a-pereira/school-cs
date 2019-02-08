CC = g++
CFLAGS = -g -Og -Wall -Werror -ansi -pedantic
LIBS = -lboost_unit_test_framework

all: ps1a

ps1a: test.o LFSR.o
	$(CC) $^ -o $@ $(LIBS)

test.o: test.cpp LFSR.hpp
	$(CC) $(CFLAGS) -c $< -o $@

LFSR.o: LFSR.cpp LFSR.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm *.o ps1a
