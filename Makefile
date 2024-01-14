all: runme

runme: main.o vectors.o Gauss.o
	g++ -Wall -o runme main.o vectors.o Gauss.o

main.o: main.cpp vectors.h Gauss.h
	g++ -Wall -c main.cpp

vectors.o: vectors.cpp vectors.h
	g++ -Wall -c vectors.cpp

Gauss.o: Gauss.cpp Gauss.h
	g++ -Wall -c Gauss.cpp

clean:
	rm -f *.o runme result.txt

