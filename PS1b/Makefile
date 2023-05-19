CC = g++
CFLAGS = -Wall -Werror -pedantic --std=c++14
LIBS = -lboost_unit_test_framework -lsfml-graphics -lsfml-window -lsfml-system
DEPS = FibLFSR.h 

#%.o: %.cpp $(DEPS)
#	$(CC) $(CFLAGS) -c $<

all: PhotoMagic

PhotoMagic: PhotoMagic.o FibLFSR.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

PhotoMagic.o: PhotoMagic.cpp
	$(CC) $(CFLAGS) -c PhotoMagic.cpp $(LIBS)

FibLFSR.o: FibLFSR.cpp FibLFSR.h
	$(CC) $(CFLAGS) -c FibLFSR.cpp $(LIBS)

clean:
	rm *.o PhotoMagic
