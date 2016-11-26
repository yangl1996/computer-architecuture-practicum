CC=gcc
CFLAGS=-lm -I. -std=c99
DEPS=decoder.h loader.h

%.o: %.c $(DEPS) ; $(CC) -c -o $@ $< $(CFLAGS)

riscv: decoder.o loader.o main.o ; $(CC) -o riscv decoder.o loader.o main.o $(CFLAGS) 

.PHONY: clean

clean: ; rm *.o *.out *.gch


