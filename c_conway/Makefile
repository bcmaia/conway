CFLAGS := -g -O0 -Wall -Wextra -pedantic
CFILES := main.c utils.c board.c

build:
	gcc $(CFLAGS) $(CFILES) -o main 

run:
	make build
	./main

test:
	clear
	make build
	valgrind --leak-check=full ./main