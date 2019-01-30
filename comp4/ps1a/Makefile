CPP = g++
CPPFLAGS = -Wall -g -std=c++11
LIBPATHS = /

app: main.o LFSR.o
	$(CPP) $(CPPFLAGS) -o app main.o LFSR.o

unit_test: test.o LFSR.o
	$(CPP) $(CPPFLAGS) -o unit_test test.o LFSR.o

main.o: main.cpp
	$(CPP) $(CPPFLAGS) -c main.cpp -o main.o

LFSR.o: LFSR.hpp LFSR.cpp
	$(CPP) $(CPPFLAGS) -c LFSR.cpp -o LFSR.o

test.o: test.cpp
	$(CPP) $(CPPFLAGS) -c test.cpp -o test.o

clean :
	rm * .o app test *~