#include "simpleio.h"
#include <stdlib.h>
#include <stdio.h>

void zigZag( int width, int rounds ) {
for ( int o = 0; o < rounds; ++o) {
	for (int i=1; i<=width; ++i) {	
		if ( o >= 1 && i == 1) {
			continue;
		}
		for ( int k=1; k<=i; k++) {
			if ( k<i)
				printf(" ");
			if ( k == i )
				printf("x");
		}
		printf("\n");
	}	
	for (int j=width-1; j>=1; --j) {
		for ( int t =1; t<=j; ++t) {
			if ( t<j)
				printf(" ");
			if (t == j)
				printf("x");
		}
		printf("\n");
	}
}
}

int main( void ) {
	
	printf("Enter a number of rounds:\n");
	int rounds = get_int();
	printf("enter a width:\n");
	int width = get_int();
	
	zigZag(width, rounds);
	
	
	// present client with bill for construction
	printf("\nThat'll be $25,000 please/thanks/bye.\n\n");

	return 0;
}
