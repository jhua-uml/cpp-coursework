CC = g++
CFLAGS = -Wall -Werror -pedantic --std=c++14
LIBS = -lboost_regex
DEPS = 

#%.o: %.cpp $(DEPS)
#	$(CC) $(CFLAGS) -c $<

all: ps7

ps7: main.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)
	
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp $(LIBS)

clean:
	rm *.o ps7
