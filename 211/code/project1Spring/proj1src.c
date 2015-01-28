// This program aims to comply with the parameters set by the following pdf
// http://www.cs.uic.edu/pub/CS211/ProjectsS15/proj1s15.pdf
// More specifically this is to sarisfy the requirements of project 1
// for the class CS211 at UIC for the spring semester of 2015

#include <stdio.h>
#include <stdlib.h>

//             ARRAY UTILS                 
int* copyArray (int size, int* originalArray) {
	int* newArray = calloc(size, sizeof(int));

	for ( int i=0; i<size; i++ ) {
		newArray[i] = originalArray[i];
	} 
	return newArray;
}

void printArr (int size, int* arr){

	for( int i=0; i<size; i++)
		printf("%d\n", arr[i]);
}
/////////////////////////////////////////////

// needed for use with qsort
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

// not finished
int* linSearch (int* arr, int size, int searchingFor) {
	int found = 0;
	int* retVals = calloc(2, sizeof(int));
	int i = 0;

	while( !found && i<size ) {
		if(arr[i] == searchingFor)
			found = 1;
		
	}
}

int main() {
	// initialize our variables, including a pointer to the beginning of
	// the array of input integers. 
	// note its size will change as we input more and more numbers
	int* arr = calloc(1, sizeof(int));
	int* arrCopy;
	int val;
	int size = 0;


	scanf(" %d", &val);
	while( val != -999)
	{
		// store the value in the array	
		
		size++;
		arr = realloc(arr, size * sizeof(int));
		arr[size-1] = val;
		scanf("%d", &val);
	}

	arrCopy = copyArray(size, arr);

	qsort(arrCopy, size, sizeof(int), cmpfunc);


	printArr(size, arr);
	printf("\n");
	printArr(size, arrCopy);

	
        return 0;
}
