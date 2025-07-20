CC = g++
CFLAGS = -Wall -O3
SRC = $(wildcard src/*.cpp)
OBJ = $(patsubst src/%.cpp,build/%.o,$(SRC))
EXEC = bin/wuttang

all: $(EXEC)

$(EXEC): $(OBJ)
	mkdir -p bin
	$(CC) $(OBJ) -o $(EXEC)

build/%.o: src/%.cpp | build
	$(CC) $(CFLAGS) -c $< -o $@

build:
	mkdir -p build

run:
	./$(EXEC)

clean:
	rm -f build/*.o $(EXEC)

.PHONY: all build run clean

