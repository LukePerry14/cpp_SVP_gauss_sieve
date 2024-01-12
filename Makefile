all: runme

runme: main.o vectors.o
	g++ -Wall -o runme main.o vectors.o

main.o: main.cpp vectors.h
	g++ -Wall -c main.cpp

vectors.o: vectors.cpp vectors.h
	g++ -Wall -c vectors.cpp

clean:
	rm -f *.o runme

