
 
#include <iostream>
#include <climits>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>

#define A 54059 /* a prime */
#define B 76963 /* another prime */
#define C 86969 /* yet another prime */

using namespace std;

struct Node {
    char* word;
    int year;
    int wordCount;
    int uniqueTextCount;
};


struct shaNode {
    unsigned sha;
    int index;
};

// grab a large chunk of memory for our main data array
Node masterList[20000000];


// hashing function taken from stackoverflow
// takes in a string, multiplies each letter by large primes, xors that result with 
// the product of two other large primes (see defined above) the result is then returned for use
// as a sha

char fileName[]="all_words.csv";
unsigned hash_str(const char* s)
{
   unsigned h = 31 /* also prime */;
   while (*s) {
     h = (h * A) ^ (s[0] * B);
     s++;
   }
   return h; // or return h % C;
}

// needed for use with qsort
int cmpfunc (const void * a, const void * b) {
  if ( ((*(shaNode*)a).sha) <  ((*(shaNode*)b).sha) ) return -1;
  if ( ((*(shaNode*)a).sha) == ((*(shaNode*)b).sha) ) return 0;
  if ( ((*(shaNode*)a).sha) >  ((*(shaNode*)b).sha) ) return 1;
}


// binary search alg
int binSearch(shaNode* array, int size, int searchValue) {
	int low = 0;
    int high = size - 1;
    int mid;
 
    while (low <= high)
    {	mid = (low + high) / 2;
 
        if(searchValue == array[mid].sha)
        {	return array[mid].index;
        }
        else if (searchValue > array[mid].sha)
        {	low = mid + 1;
        }
        else
        {	high = mid - 1;
        }
    }

    // at this point, nothing has been found so we should return a -1 value
    return -1;
}


 
int main()
{
    FILE *inFile;    // declare file pointer
    inFile = fopen( fileName,"r");
 
    printf("Reading in file. Be patient please. I am only as fast as my crystal.\n");
         
    // variables that correspond to input file fields
    char word[ 81];
    int year;
    int wordCount;
    int uniqueTextCount;
    unsigned sha;
    int index = 0;
    int hashTableSize = 0;
    int shaIndex = 0;
    int shaSize = 0;
    Node dataPoint;
    // initialize table of hashes with room for a single hash
    shaNode* shaTable = (shaNode*)calloc(1, sizeof(shaNode));

    while( fscanf( inFile, "%s %d %d %d", word, &year, &wordCount, &uniqueTextCount) != EOF) {
        // store in as a node in our master structure
        // check if this is a new word
        // if it is a new word { calculate sha, store [sha, word, startingIndex] into hash table IN ORDER of what the sha is}
        // if it is a new word { change the current to the value of new word }
	    if ( index != 0) {
    
            if ( strcmp(word, masterList[ index-1 ].word) != 0) {  // if this is a new word
                                                           // create a new sha node and add it to the list
                sha = hash_str(word);
                shaNode tempShaNode;
                tempShaNode.sha      = sha;
                tempShaNode.index    = index;
                
                shaSize++;
                if( shaSize>1 )
                	shaTable = (shaNode*)realloc(shaTable, sizeof(shaNode)*shaSize);

                shaTable[ shaIndex ] = tempShaNode;
                shaIndex++;
            }
        }

        dataPoint.word = (char*)calloc(81, sizeof(char));
        memcpy(dataPoint.word, word, 81); 
        dataPoint.year = year;      
        dataPoint.wordCount = wordCount;
        dataPoint.uniqueTextCount = uniqueTextCount;
	
	    masterList[ index ] = dataPoint;

        index++;
    }


    qsort(shaTable, shaSize, sizeof(shaNode), cmpfunc);

	printf("\nWhat word would you like to know about?  ");
	char searchTerm[ 81];
	scanf(" %s", searchTerm);

	unsigned search = hash_str(searchTerm);
	int mainSearchIndex = binSearch(shaTable, shaSize, search);
	printf("the data is located at index: %d\n", mainSearchIndex );
	for(int i=0; strcmp(masterList[mainSearchIndex].word, masterList[mainSearchIndex + i].word) == 0; i++) {
		printf("word: %s\n year: %d\n freq: %d\n texts: %d\n", masterList[mainSearchIndex+i].word, masterList[mainSearchIndex+i].year, masterList[mainSearchIndex+i].wordCount, masterList[mainSearchIndex].uniqueTextCount );
	}
    return 0;
}
