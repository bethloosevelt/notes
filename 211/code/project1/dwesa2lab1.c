/*
Dale Wesa
dwesa2@uic.edu
UIN: 676019303
CS 211 - project 1 
08/28/14

This program is to demonstrate basic operations in C
with the use of pointers, console input, and functions
*/ 

#include <stdio.h>
#include <stdlib.h> 

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


int sum(int *arr) {
	int sum;
	for ( int i = 0; i < 10; i++ ) {
		sum += *arr;
		arr++;
	}
	return sum;
}


void adjust(int *arr) {
	for ( int i = 0; i < 10; i++) {
		int adjustment = rand()%10;	
		*arr += adjustment;
		arr++;
	}
}

void print(int *ptr){
	for ( int i = 0; i < 10; i++ ) {
		printf( "%d\t", *ptr );	
		ptr++;
	}
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


	int array[10];
	int *ptr = &array[0];

	printf("Please enter 10 integers");
	
	for ( int i = 0; i < 10; i++ ) {
		scanf( "%d", ptr );	
		ptr++;
	}
	
	int total = sum( &array[0] );
	printf( "\nSum of elements in array: %d\n", total );

	printf("\nBefore adjust:\n");
	print( &array[0] );
	adjust( &array[0] );
	printf("\nAfter adjust:\n");
	print( &array[0] );
	print("\n");
}

