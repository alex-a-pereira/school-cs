CPP = g++
CPPFLAGS = -Wall -g -std=c++11
LIBPATHS = /

app: main.o LSFR.o
	$(CPP) $(CPPFLAGS) -o app main.o LSFR.o

unit_test: test.o LSFR.o
	$(CPP) $(CPPFLAGS) -o unit_test test.o LSFR.o

main.o: main.cpp
	$(CPP) $(CPPFLAGS) -c main.cpp -o main.o

LSFR.o: LSFR.hpp LSFR.cpp
	$(CPP) $(CPPFLAGS) -c LSFR.cpp -o LSFR.o

test.o: test.cpp
	$(CPP) $(CPPFLAGS) -c test.cpp -o test.o

clean :
	rm * .o app test *~