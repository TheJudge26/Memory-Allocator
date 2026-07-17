flags=-m32 -O2 -Wall -std=c2x

.PHONY: clean

all: clean Alloc

Alloc: Alloc.o heap.o
	cc $(flags) $^ -o $@

Alloc.o: Alloc.c Alloc.h
	cc $(flags) -c $<

heap.o: heap.asm
	nasm -f elf $^

clean:
	rm -f *.o Alloc