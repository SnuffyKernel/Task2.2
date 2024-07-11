CC=gcc

CFLAGS= -Wall -Werror -Wextra

SRC=main.c error/error.c function_phone_book/function.c phone_book/phone_book.c

TARGET=phone_book.out

all: build

build:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -rf $(TARGET)