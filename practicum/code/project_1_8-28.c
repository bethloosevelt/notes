#include <stdio.h>

int main() {
	
	// variable declaration
	int firstInt = 0;
	int secondInt = 0;

	// interface with user
	printf("NAME: Dale Wesa \n UIN: 676019303\n");	
	printf("\nenter a couple of integers: \n");
	
	// read bits from stdin as int into address of firstInt
	scanf("%d", &firstInt);
	// do the same for another variable
	scanf("%d", &secondInt);
	
	printf("\nFirst: %d\tSecond: %d\n", firstInt, secondInt);

}
