CC = gcc
CFLAGS = -Wall -g

all: programa

programa: main.o heap.o avl.o pontos.o
	$(CC) $(CFLAGS) -o programa main.o heap.o avl.o pontos.o

main.o: main.c pontos.h
	$(CC) $(CFLAGS) -c main.c

heap.o: heap.c heap.h
	$(CC) $(CFLAGS) -c heap.c

avl.o: avl.c avl.h
	$(CC) $(CFLAGS) -c avl.c

pontos.o: pontos.c pontos.h heap.h avl.h
	$(CC) $(CFLAGS) -c pontos.c

clean:
	rm -f *.o programa