CC = gcc
CFLAGS = -Wall -Wextra

all: tic-tac-toe

tic-tac-toe: main.c common.h pvp.h pve.h
	$(CC) $(CFLAGS) -o $@ main.c

clean:
	rm -f tic-tac-toe

.PHONY: all clean