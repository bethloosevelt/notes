#include <stdlib.h>
#include <stdio.h>

int main (void) {
	int i=0;
	for(printf("\nthings%d", i); 1; i+=3)
		printf("\ninloop%d", i);
return 0;
}
