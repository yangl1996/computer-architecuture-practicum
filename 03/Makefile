CC=gcc
CFLAGS=-I. -std=c99 -DDEBUG
DEPS=decoder.h loader.h

%.o: %.c $(DEPS) ; $(CC) -c -o $@ $< $(CFLAGS)

riscvemu: decoder.o loader.o main.o ; $(CC) -o riscvemu decoder.o loader.o main.o $(CFLAGS)

.PHONY: clean

clean: ; rm *.o *.out *.gch

