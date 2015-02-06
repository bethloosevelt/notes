

impleio.o: simpleio.h simpleio.c
	gcc -std=c99 -c simpleio.c

log: log.c simpleio.o
	gcc -std=c99 -o log log.c simpleio.o

zigzag: zigzag.c simpleio.o
	gcc -std=c99 -o zigzag zigzag.c simpleio.o

