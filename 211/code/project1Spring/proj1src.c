// This program aims to comply with the parameters set by the following pdf
// http://www.cs.uic.edu/pub/CS211/ProjectsS15/proj1s15.pdf
// More specifically this is to sarisfy the requirements of project 1
// for the class CS211 at UIC for the spring semester of 2015

#include <stdio.h>
#include <stdlib.h>

int main() {
	// initialize our variables, including a pointer to the beginning of
	// the array of input integers. 
	// note its size will change as we input more and more numbers
	int *arr = calloc(1, sizeof(int));
	int val;
	int size = 0;

	scanf("%d", &val);
	while( val != -999)
	{
		// store the value in the array	
		arr[size] = val;
		size++;
		arr = realloc(arr, size * sizeof(int));

		scanf("%d", &val);
	}

	for( int i=0; i<size; i++)
		printf("%d\n", arr[i]);

        return 0;
}
