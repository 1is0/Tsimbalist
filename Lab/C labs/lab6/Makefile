all: build run clean

build:
	gcc -std=c89 -pedantic-errors main.c list.c tree.c -o program

run: program
	./program
	
clean:
	rm -rf *.o program