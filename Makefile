CC = gcc
CFLAGS = -Wall -g

%:
	$(CC) $@.c -o bin/$@ $(CFLAGS)
