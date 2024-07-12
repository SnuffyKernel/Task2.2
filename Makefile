CC=gcc

CFLAGS= -Wall -Werror -Wextra

SRC=main.c operation.c parser.c

TARGET=main

all: build

build:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -rf $(TARGET)