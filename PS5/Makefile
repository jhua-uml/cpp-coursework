CC = g++
CFLAGS = -pedantic --std=c++17
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
DEPS = EDistance.h

#%.o: %.cpp $(DEPS)
#	$(CC) $(CFLAGS) -c $<

all: EDistance

EDistance: main.o EDistance.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

main.o: main.cpp EDistance.h
	$(CC) $(CFLAGS) -c main.cpp $(LIBS)

EDistance.o: EDistance.cpp EDistance.h
	$(CC) $(CFLAGS) -c EDistance.cpp $(LIBS)

clean:
	rm *.o EDistance
