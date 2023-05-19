CC = g++
CFLAGS = -pedantic --std=c++14
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
DEPS = Triangle.h

#%.o: %.cpp $(DEPS)
#	$(CC) $(CFLAGS) -c $<

all: TFractal

TFractal: TFractal.o Triangle.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

TFractal.o: TFractal.cpp Triangle.h
	$(CC) $(CFLAGS) -c TFractal.cpp $(LIBS)

Triangle.o: Triangle.cpp Triangle.h
	$(CC) $(CFLAGS) -c Triangle.cpp $(LIBS)

lint:
	cpplint --quiet *.cpp *.h

clean:
	rm *.o TFractal
