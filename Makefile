# Makefile

CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Wpedantic -Wconversion
TARGET = main
SRC = main.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
