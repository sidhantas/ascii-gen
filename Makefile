CC=clang
CFLAGS=-g

all: ascii-gen invertbitmap

ascii-gen: ascii-gen.c vector_to_image.o
	$(CC) $(CFLAGS) -c ascii-gen.c
	$(CC) ascii-gen.o vector_to_image.o -o ascii-gen

invertbitmap: invertbitmap.c
	$(CC) $(CFLAGS) invertbitmap.c -o invertbitmap

vector_to_image.o: vector_to_image.c vector_to_image.h
	$(CC) $(CFLAGS) -c vector_to_image.c

clean: 
	rm -f *.o read-mnist invertbitmap
