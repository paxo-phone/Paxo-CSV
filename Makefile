CC = g++
SRC = example.cpp csv.cpp
EXEC = build/main
FLAGS = -std=c++11


all: $(SRC)
	mkdir -p build
	$(CC) $(SRC) -o $(EXEC) $(FLAGS)


clean:
	rm -rf $(EXEC)