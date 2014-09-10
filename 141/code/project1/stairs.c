#include "simpleio.h"
#include <stdlib.h>
#include <stdio.h>

void printUp( int steps ) {

	printf("\nGoing up: \n");

	for (int i=1; i<=steps; ++i)
	{	
		for (int j=steps; j>i; --j)
		{
			printf(" ");
		}	
		for (int k=1; k<=i; ++k)
		{
			printf("#");
		}
		
		printf("\n");
	}
}

// simply switch the order of printing the spaces vs the hashes
void printDown( int steps ) {

	printf("\nGoing down: \n");

	for (int i=1; i<=steps; ++i)
	{		
		for (int k=1; k<=i; ++k)
		{
			printf("#");
		}

		for (int j=steps; j>=i; --j)
		{
			printf(" ");
		}		

		printf("\n");
	}
}

// need two loops for printing hashes so that the top step 
// only has a single hash
// the only difference is that the first time through the outer loop
// the second hash loop prints nothing
void printBoth( int steps ) {

	printf("\nGoing up then down: \n");

	for (int i=1; i<=steps; ++i)
	{		
		for (int j=steps; j>i; --j)
		{
			printf(" ");
		}

		for (int k=1; k<=i; k++)
		{
			printf("#");
		}

		for (int k=1; k<i; k++)
		{
			printf("#");
		}

		for (int l=steps; l>=i; --l)
		{
			printf(" ");
		}		

		printf("\n");
	}
}


int main( void ) {
	
	printf("Enter a number to build your stairs:\n");
	int steps = get_int();
	
	// pass the value to our functions
	// no return value is given
	printUp( steps );
	printDown( steps );
	printBoth( steps );
	
	// present client with bill for construction
	printf("\nThat'll be $25,000 please/thanks/bye.\n\n");

	return 0;
}
