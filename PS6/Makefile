CC = g++
CFLAGS = -pedantic --std=c++17
LIBS = -lboost_unit_test_framework
DEPS = 

#%.o: %.cpp $(DEPS)
#	$(CC) $(CFLAGS) -c $<

all: TextWriter test

TextWriter: main.o RandWriter.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

test: test.o RandWriter.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

main.o: main.cpp RandWriter.h
	$(CC) $(CFLAGS) -c main.cpp $(LIBS)

RandWriter.o: RandWriter.cpp RandWriter.h
	$(CC) $(CFLAGS) -c RandWriter.cpp $(LIBS)

test.o: test.cpp RandWriter.h
	$(CC) $(CFLAGS) -c test.cpp $(LIBS)

clean:
	rm *.o TextWriter
