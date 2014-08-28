#include <stdio.h>

// variable declaration
int firstInt;
int secondInt;

int max(int first, int second) {
	
	// simply compare the two, returning the larger
	int larger = first;
	if ( second > larger )
		larger = second;

	return larger;
}


void swap(int * first, int * second) {
	int swap = *second;
	*second  = *first;
	*first   = swap;	
}


int main() { 
	int larger = 0;

	// interface with user
	printf("NAME: Dale Wesa \n UIN: 676019303\n");	
	printf("\nenter a couple of integers: \n");
	
	// read bits from stdin as int into address of firstInt
	scanf("%d", &firstInt);
	// do the same for another variable
	scanf("%d", &secondInt);

	// pass the two input ints to our max function, storing the
	// return value	

	
	printf("\npre-swap:\n");	
	printf("First: %d\tSecond: %d\n\n", firstInt, secondInt);
	
	swap(&firstInt, &secondInt);	

	printf("post-swap:\n");	
	printf("First: %d\tSecond: %d\n", firstInt, secondInt);
	
	larger = max(firstInt, secondInt);
	printf("\nThe lerger number is: %d\n", larger);

}

