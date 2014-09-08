#include <stdio.h>
#include <stdlib.h>

// a tool used while reading in an array of variable size to 
// reallocate memory for a larger number of integers, maintaining
// the original data stored in the array
int * incrimentArraySize(int * array, int size) {

	int * temp = (int *) malloc(sizeof(int) * (size+1));
	
	// copy over contents from original array to temporary holder
	for (int i = 0; i < size; i++)
		temp[i] = array[i];	
	free(array);
	return temp;
}

// a function to copy an array into a newly allocated pointer
// returns new array
int * copy(int * original, int size) {

	int * new = (int * ) malloc(sizeof(int)*size);
	for (int i = 0; i < size; i++)
		new[i] = original[i];
	return new;
}

// prints an array in a comma delimited line. Checks to make 
// sure no comma is printed after final item in array is printed
void printArr(int * array, int size) {
	
	for (int i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i+1 != size)
			printf(", ");
	}
	printf("\n");
}


void moveFront(int * array, int dataIndex, int frontIndex) {
	printf("inside moveFront");
	// first move the desired data to the front, saving whatever is there
	int temp, temp2;

	// first move the desired data to the front, saving whatever is there
	temp = array[frontIndex];
	array[frontIndex] = array[dataIndex];
	
	// now we need to shift over the rest of the array
	while(frontIndex < dataIndex)
	{	frontIndex++;
		// take the first element
		// replace it with the one we saved in temp
		// now shift temp2 over to temp
		// repeat until all items up to 
		temp2 = array[frontIndex];
		array[frontIndex] = temp;
		temp = temp2;
	}

}

void sort(int * array, int left, int right) {
	int pivot = array[0];
	
	// check all items to left of pivot
	for (int i = 1; i <= right; i++)
	{	//printf("%d", array[i]);
		if( array[i] <= pivot)	
		{	
			moveFront(array, i, left);
		}
	}	
        printArr(array, right);	
	if(right-left > 1)
	{
		sort(array, (right-left)/2, right);
		//	sort(array, left, right/2);
	}
}

int main(void) {

	printf( "Please begin entering integers. \nWhen you are finished with your list, enter \"-999\"\n" );

	int input;
	int * arr = (int *)malloc( sizeof(int));
	int size = 1;
	int slot = 0;
	int * copyArray;

	while( scanf("%d", &input))
	{
		if ( input == -999)
			break;

		arr[slot] = input;
		arr = incrimentArraySize(arr, size);
		size++;
		slot++;	
	}
	size--;

	int * copied = copy(arr, size);

	printArr(arr, size);
	printArr(copied, size);

	sort(arr, 0, size);
	
return 0;

}
