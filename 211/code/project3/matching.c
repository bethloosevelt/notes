#include <stdio.h>
#include <stdlib.h>


int isOpener(char symbol) {
	if ( symbol == "(" || symbol == "{" || symbol == "[" || symbol == "<" ) 
		return 1;
	else 
		return 0;
}

int isCloser(char symbol) {
	if ( symbol == ")" || symbol == "}" || symbol == "]" || symbol == ">" ) 
		return 1;
	else 
		return 0;
}

int main (void) {

	int MAXSIZE = 300;

	// initialize a character array to store the line read
	// in from the console
	// read in a string of up to 300 characters (NULL included)
	// storing this beginning at *line
	char* line = (char*) malloc( sizeof(char)*MAXSIZE );
	fgets( line, MAXSIZE, stdin );

	printf("%s", line);	

	char symbol = " ";
	while ( symbol != NULL)
	{
		symbol = line;
		printf("c", symbol);
		(*line)++;
		if ( isOpener(symbol) )
			printf("\nopener");
		else
			if ( isCloser(symbol) )
				printf("\ncloser");
	}
	

	return 0;
}
