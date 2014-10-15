#include <stdio.h>
#include <stdlib.h>

int getLargest(int A, int B, int C, int D) {

	int max = A;
	if (B > max)
		max = B;
	if (C > max)
		max = C;
	if (D > max)
		max = D;
	return max;
}

int getInt() {

	int number;
	scanf("%d", &number);

	if ( number > 0 )
		return number;

	while(1)
	{
		printf("Try again: ");
		scanf("%d", &number);
		 if ( number > 0 )
		 	return number;
	}
}

int main(void) {

	int A, B, C, D;
	int max;

	printf("Enter how many people got each grade:");
	printf("\nA: ");
	A = getInt();
	printf("B: ");
	B = getInt();
	printf("C: ");
	C = getInt();
	printf("D: ");
	D = getInt();

	max = getLargest(A, B, C, D);
	
	for ( int i=max; i>0; --i)
	{
		if (A >= i)		
			printf("X ");
		else
			printf("  ");	
		if (B >= i)		
			printf("X ");
		else
			printf("  ");
		if (C >= i)		
			printf("X ");
		else
			printf("  ");
		if (D >= i)		
			printf("X ");
		else
			printf("  ");
		printf("\n");
	}
	printf("--------");
	printf("\nA B C D \n");
	return 0;
}