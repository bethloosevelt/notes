#include <stdio.h>
#include <stdlib.h>

// define global constants	
char openers[4] = ["(", "{", "[", "<"]
char closers[4] = [")", "}", "]", ">"]

int isOpener(char symbol) {


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
	for ( int i=0; symbol!=NULL; ++i )
	{
		symbol = line[i];
		if ( isOpener(symbol); )
		
		
		push(symbol);
	}
	

	return 0;
}
