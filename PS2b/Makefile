CC = g++
CFLAGS = -pedantic --std=c++14
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
DEPS = CelestialBody.h

#%.o: %.cpp $(DEPS)
#	$(CC) $(CFLAGS) -c $<

all: NBody

NBody: main.o CelestialBody.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

main.o: main.cpp Universe.h
	$(CC) $(CFLAGS) -c main.cpp $(LIBS)

CelestialBody.o: CelestialBody.cpp CelestialBody.h
	$(CC) $(CFLAGS) -c CelestialBody.cpp $(LIBS)

clean:
	rm *.o NBody
