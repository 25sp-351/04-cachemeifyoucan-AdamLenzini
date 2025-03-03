all: main

OBJS = main.o vector.o rodcut.o
CC = clang
CFLAGS = -g -Wall

main: $(OBJS)
	$(CC) -o $@ $(CFLAGS) $(OBJS)

vector.o: vector.h

rodcut.o: rodcut.h vector.h

main.o: vector.h rodcut.h

clean:
	rm -f main $(OBJS)