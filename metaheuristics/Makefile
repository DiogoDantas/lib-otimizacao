# compiler
CC = g++
# flags
FLAGS = -O2 -g3 -std=c++11

all:
	$(CC) src/*.cpp tests/test_parser.cpp $(FLAGS) -o test_parser.o
	$(CC) src/parser.cpp src/vnd.cpp $(FLAGS) -o vnd.o
clean:
	rm vnd

