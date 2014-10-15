hist: hist.c
	gcc hist.c -std=c99 -o hist
quiz: quiz.c
	gcc quiz.c -std=c99 -o quiz
util.o: util.c util.h
	gcc util.c -c -std=c99
util_tst: util_tst.c util.o	
	gcc util_tst.c util.o -std=c99 -o util_tst
