CC = g++
CFLAGS = -Wall -Werror -pedantic --std=c++14
LIBS = -lboost_unit_test_framework
DEPS = FibLFSR.h 

#%.o: %.cpp $(DEPS)
#	$(CC) $(CFLAGS) -c $<

all: main ps1a

ps1a: FibLFSR.o test.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

main: main.o FibLFSR.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)
	
FibLFSR.o: FibLFSR.cpp FibLFSR.h
	$(CC) $(CFLAGS) -c FibLFSR.cpp $(LIBS)

main.o: main.cpp FibLFSR.h
	$(CC) $(CFLAGS) -c main.cpp $(LIBS)

test.o: FibLFSR.h
	$(CC) $(CFLAGS) -c test.cpp $(LIBS)

clean:
	rm *.o ps1a
