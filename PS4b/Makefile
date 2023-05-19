CC = g++
CFLAGS = -pedantic --std=c++17
LIBS = -lboost_unit_test_framework -lsfml-graphics -lsfml-audio -lsfml-system -lsfml-window -lsfml-system
DEPS = CircularBuffer.h StringSound.h

#%.o: %.cpp $(DEPS)
#	$(CC) $(CFLAGS) -c $<

all: ps4a main

ps4a: test.o CircularBuffer.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

main: main.o CircularBuffer.o StringSound.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

main.o: main.cpp CircularBuffer.h
	$(CC) $(CFLAGS) -c main.cpp $(LIBS)

CircularBuffer.o: CircularBuffer.h
	$(CC) $(CFLAGS) -c CircularBuffer.cpp $(LIBS)

StringSound.o: StringSound.h CircularBuffer.h
	$(CC) $(CFLAGS) -c StringSound.cpp $(LIBS)

test.o: CircularBuffer.h
	$(CC) $(CFLAGS) -c test.cpp $(LIBS)
	
#SSLite: SSLite.o CircularBuffer.o StringSound.o
#	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

#SSLite.o: CircularBuffer.h StringSound.h
#	$(CC) $(CFLAGS) -c SSLite.cpp $(LIBS)

clean:
	rm *.o main ps4a
