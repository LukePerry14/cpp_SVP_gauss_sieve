GXX = g++
FLAGS = -Wall
TARGET = runme

all: $(TARGET)

$(TARGET): main.o vectors.o Gauss.o
	$(GXX) $(FLAGS) -o runme main.o vectors.o Gauss.o

test: $(TARGET)
	./$(TARGET) [64.0 218.0 133.0] [71.0 205.0 111.0] [28.0 -48.0 -84.0]

main.o: main.cpp vectors.h Gauss.h
	$(GXX) $(FLAGS) -c main.cpp

vectors.o: vectors.cpp vectors.h
	$(GXX) $(FLAGS) -c vectors.cpp

Gauss.o: Gauss.cpp Gauss.h
	$(GXX) $(FLAGS) -c Gauss.cpp

clean:
	rm -f *.o runme result.txt

