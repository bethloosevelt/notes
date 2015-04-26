
simpleio.o: simpleio.c simpleio.h
	gcc -c simpleio.c

bboard.o:  bboard.c bboard.h
	gcc -c bboard.c

bpop: bpop.c bboard.o simpleio.o 
	gcc bpop.c -o bpop bboard.o simpleio.o
