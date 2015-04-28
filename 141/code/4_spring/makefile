balanced: balanced.c
	gcc -std=c99 balanced.c -o balanced
headings: headings.c
	gcc -std=c99 headings.c -o print_headings
stack.o: stack.c stack.h
	gcc -std=c99 -c stack.c

stacker: stack.o main.c
	gcc -std=c99 main.c stack.o -o stacker
