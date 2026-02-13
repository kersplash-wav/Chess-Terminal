CC = gcc
CFLAGS = -std=c99
TARGET = chess
OBJ = main.o piece.o stage.o input.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(TARGET)

%.o: %.c chess.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf $(OBJ) $(TARGET)

.PHONY: 
	all clean

run: $(TARGET)
	./$(TARGET)
