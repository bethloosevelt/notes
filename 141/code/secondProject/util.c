#include "util.h"
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



int is_sorted(int a[], int n) {

	int i;
	for ( i=0; i<n-1; i++ ) {

		if ( a[i] <= a[i+1] )
			continue;
		else
			return 0;
	}
	return 1;
}



void histogram(unsigned int data[], int n) {

	if ( n>26 || n<0 ) {
		printf("invalid array size");
		return;
	}
	// find largest data point
	int i =0;
	int largest = 0;
	for ( i=0; i<n; i++) {
		if ( data[i] > largest )
			largest = data[i];
	}

	int k;
	for ( i=largest; i>0; i-- ) {
		printf(" ");
		for ( k=0; k<n; k++ ) {
			if ( data[k] >= i )
				printf("X");
			else
				printf(" ");
		}
		printf("\n");
	}


	for ( i=0; i<=n+1; i++)
		printf("-");

	printf("\n ");
	// askii A is 65
	int letter;
	for ( letter=65; letter<n+65; letter++)
		printf("%c", letter);

	printf("\n");
}


int num_occ(int data[],  int n, int x) {

	int i =0;
	int count = 0;
	for ( i=0; i<n; i++) {
		if ( data[i] == x )
			count++;
	}

	return count;
}


int num_distinct(int a[], int n) {

	int* subset = calloc(n, sizeof(int));
	int distinctSize = 0;
	subset[distinctSize] = a[0];
	distinctSize++;
	int i;
	int k;

	int unique = 1;

	for ( i=1; i<n; i++ ) {
		unique = 1;
		for ( k=0; k<distinctSize; k++ ) {
			if ( a[i] == subset[k] )
				unique = 0;
		}
		if ( unique ) {
			subset[distinctSize] = a[i];
			distinctSize++;
		}
	}

	free ( subset );
	return distinctSize;

}


int same_contents(int a[], int b[], int n) {

	int* sortedA = calloc(n, sizeof(int));
	int* sortedB = calloc(n, sizeof(int));
	int i;
	for ( i=0; i<n; i++ ) {
		sortedA[i] = a[i];
		sortedB[i] = b[i];
	}

	int swap;
	int j;

	for (i = 0; i < n; ++i)
    {
        for (j = i + 1; j < n; ++j)
        {
            if (sortedA[i] > sortedA[j])
            {
                swap =  sortedA[i];
                sortedA[i] = sortedA[j];
                sortedA[j] = swap;
            }
        }
    }

	for (i = 0; i < n; ++i)
    {
        for (j = i + 1; j < n; ++j)
        {
            if (sortedB[i] > sortedB[j])
            {
                swap =  sortedB[i];
                sortedB[i] = sortedB[j];
                sortedB[j] = swap;
            }
        }
    }

	int match = 1;

	for ( i=0; i<n; i++ ) {
		if ( sortedA[i] == sortedB[i])
			continue;
		else
			match = 0;
	}

	free(sortedA);
	free(sortedB);
	return match;

}


int sift(int a[], int b[], int n, int p) {
	
	int piv = a[p];
	int bindex = 0;
	int i;
	for ( i=0; i<n; i++) {
		if ( a[i] <= piv) {
			b[bindex] = a[i];
			bindex++;
		}
	} 

	int startSecondPartition = bindex;
	for ( i=0; i<n; i++) {
		if ( a[i] > piv) {
			b[bindex] = a[i];
			bindex++;
		}
	} 

	return startSecondPartition;
}
