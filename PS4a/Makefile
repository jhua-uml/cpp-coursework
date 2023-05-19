CC = g++
CFLAGS = -pedantic --std=c++17
LIBS = -lboost_unit_test_framework
DEPS = CircularBuffer.h

#%.o: %.cpp $(DEPS)
#	$(CC) $(CFLAGS) -c $<

all: main ps4a

ps4a: test.o CircularBuffer.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

main: main.o CircularBuffer.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

main.o: main.cpp CircularBuffer.h
	$(CC) $(CFLAGS) -c main.cpp $(LIBS)

CircularBuffer.o: CircularBuffer.h
	$(CC) $(CFLAGS) -c CircularBuffer.cpp $(LIBS)

test.o: CircularBuffer.h
	$(CC) $(CFLAGS) -c test.cpp $(LIBS)

clean:
	rm *.o main ps4a
