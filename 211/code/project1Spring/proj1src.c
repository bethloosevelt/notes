// This program aims to comply with the parameters set by the following pdf
// http://www.cs.uic.edu/pub/CS211/ProjectsS15/proj1s15.pdf
// More specifically this is to sarisfy the requirements of project 1
// for the class CS211 at UIC for the spring semester of 2015

#include <stdio.h>
#include <stdlib.h>

int* expandArr(int size, int* oldArr)
{	
	// declare a new integer array pointer
	// whos size is just right for the number of ints we have to store
	int* newArr = (int*)malloc( size*sizeof(int) );

	for (int i=0; i<size; i++)
		newArr[i] = oldArr[i];
	free(oldArr);

	return newArr;	
}

int main() {
	// initialize our variables, including a pointer to the beginning of
	// the array of input integers. 
	// note its size will change as we input more and more numbers
	int *arr = (int*)malloc(sizeof(int));
	int val;
	int size = 0;

	scanf("%d", &val);
	while( val != -999)
	{
		// store the value in the array	
		arr[size] = val;
		// increase the size of the array to reflect the number of stored ints
		size++;
		// expand the array for another integer
		arr = expandArr(size, arr);

		scanf("%d", &val);
	}

	for( int i=0; i<size; i++)
		printf("%d\n", arr[i]);

return 0;
}
