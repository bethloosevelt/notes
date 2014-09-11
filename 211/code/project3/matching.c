#include <stdio.h>
#include <stdlib.h>


int isOpener(char symbol, char* openers) {
	for ( int i=0; i<5; ++i )
	{
		if ( symbol == openers[i] )
		printf("c", openers[i]);
		return 1;
	}
	return 0;
}

int main (void) {
	char* openers;
	char* closers;

	closers = (char*) malloc(sizeof(char)*5);
	openers = (char*) malloc(sizeof(char)*5);
	openers[0] = "(";
	openers[1] = "{";
	openers[2] = "[";
	openers[3] = "<";
	openers[4] = NULL;
	
	closers[0] = ")";
	closers[1] = "}";
	closers[2] = "]";
	closers[3] = ">";
	closers[4] = NULL;


	int MAXSIZE = 300;

	// initialize a character array to store the line read
	// in from the console
	// read in a string of up to 300 characters (NULL included)
	// storing this beginning at *line
	char* line = (char*) malloc( sizeof(char)*MAXSIZE );
	fgets( line, MAXSIZE, stdin );

	printf("%s", line);	

	char symbol = " ";
	for ( int i=0; symbol!=NULL; ++i )
	{
		symbol = *line[i];
		if ( isOpener(symbol, openers) )
			printf("\nyes");
		else
			printf("\nno");
	}
	

	return 0;
}
