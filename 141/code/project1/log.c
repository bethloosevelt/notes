// dale wesa
// 676019303
// feb 2015


#include "simpleio.h"
#include <stdlib.h>
#include <stdio.h>

void findLog(int input) {
	int found = 0;
	int solution=0;
	int prod = 1;
	while ( 1  ) {
		if (prod >= input)
			break;
		prod = prod*2;
		solution++; 
	}
	if (prod > input)
		solution--;
		
	printf("Log2( %d ) = %d", input, solution);

}

int main( void ) {
	int input;
	int positive = 0;
	while( !positive ) {
		printf("enter a positive integer: \n");
		input = get_int();
		if ( input > 0 )
			positive = 1;
	}
	findLog(input);


	return 0;
}
