//#include "util.h"
#include <stdio.h>
#include <stdlib.h>

// actual implementation of utility functions declared in util.h go here...



void print_arb_base(unsigned int n, unsigned int b) {
	// input number = n
	// base = b
	printf("\n%d in base %d is:\t", n, b);

	int* number = calloc(10, sizeof(int));
	int i = 0;

	while( n>0 ) {

		number[i] = n % b;
		n = n/b;
		i++;
	}	

	i--;  // we incrimented i one extra time when n turned out to be zero
	while( i >= 0 ) {

		printf("%d", number[i]);
		i--;
	}
	
	printf("\n");
}



int main() {

	print_arb_base(5, 2);

	return 0;
}