CC = g++
CFLAGS = -Wall -O2
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
EXEC = wuttang

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: all clean

