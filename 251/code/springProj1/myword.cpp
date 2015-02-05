
 
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

struct  aveNode {
    int firstYear;
    int lastYear;
    int average;
};

struct yearNode {
    int wordListSize;
    int year;
    char** uniqueWordList;
};



// grab a large chunk of memory for our main data array
Node masterList[20000000];

// hashing function taken from stackoverflow
// takes in a string, multiplies each letter by large primes, xors that result with 
// the product of two other large primes (see defined above) the result is then returned for use
// as a sha


// void addAverageNode(aveNode* aveList, int aveSize, int firstYear, int lastYear, int average) {

   
// }


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

    int yearListSize = 1;
    int wordPlaced = 0;

    unsigned sha;
    int index = 0;
    int hashTableSize = 0;
    int shaIndex = 0;
    int shaSize = 0;
    Node dataPoint;
    // initialize table of hashes with room for a single hash
    shaNode* shaTable = (shaNode*)calloc(1, sizeof(shaNode));
    yearNode* yearList = (yearNode*)calloc(1, sizeof(yearNode));

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



        for( int  i=0; i< yearListSize; i++) {
            if ( yearList[i].year == year ) {
                yearList[i].wordListSize++;
                yearList[i].uniqueWordList = (char**)realloc(yearList[i].uniqueWordList, yearList[i].wordListSize * sizeof(char*));
                yearList[i].uniqueWordList[yearList[i].wordListSize-1] = (char*)calloc(81, sizeof(char));
                memcpy( yearList[i].uniqueWordList[yearList[i].wordListSize-1], word, 81);
                wordPlaced = 1;
            } 
            if (wordPlaced)
                break;
        }
        if (!wordPlaced) {
            if(yearListSize > 1) {
                yearList = (yearNode*) realloc(yearList, yearListSize * sizeof(yearNode));
            }
            yearNode tempYearNode;
            tempYearNode.year = year;
            tempYearNode.wordListSize = 1;
            tempYearNode.uniqueWordList = (char**)calloc(1, sizeof(char*));
            tempYearNode.uniqueWordList[0] = (char*)calloc(81, sizeof(char));
            memcpy(tempYearNode.uniqueWordList[0], word, 81); 

            yearList[yearListSize-1] = tempYearNode;
            yearListSize++;
        }

        wordPlaced =0;

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

    int firstYear = masterList[ mainSearchIndex ].year;
    aveNode* aveList = (aveNode*) calloc(1, sizeof(aveNode));

    int aveSize = 0;
    int average = 0;
    int lastYear = 0;
    int largestAverage = 0;

	printf("the data is located at index: %d\n", mainSearchIndex );
	for(int i=0; strcmp(masterList[mainSearchIndex].word, masterList[mainSearchIndex + i].word) == 0; i++) {
		//printf("word: %s\n year: %d\n freq: %d\n texts: %d\n", masterList[mainSearchIndex+i].word, masterList[mainSearchIndex+i].year, masterList[mainSearchIndex+i].wordCount, masterList[mainSearchIndex+i].uniqueTextCount );
	   
        average += masterList[ mainSearchIndex + i ].wordCount;
        if( (i!=0 && i%5 == 0) || !(strcmp(masterList[mainSearchIndex].word, masterList[mainSearchIndex + i + 1].word) == 0) )  {  // every fifth term start a new average and save the span of years
            lastYear = masterList[ mainSearchIndex + i ].year;
            aveSize++;

            if( aveSize > 1)
                aveList = (aveNode*) realloc(aveList, sizeof(aveNode)*aveSize );

            aveList[aveSize-1].firstYear = firstYear;
            aveList[aveSize-1].lastYear  = lastYear;
            aveList[aveSize-1].average   = average;

            if ( average > largestAverage)
                    largestAverage = average;

            average = 0;
            firstYear = masterList[ mainSearchIndex + i + 1 ].year;
        }
    }

    // print average list
    for ( int i=0; i<aveSize; i++)
        printf(" %d\t%d\t%d\n", aveList[i].firstYear, aveList[i].lastYear, aveList[i].average);

    // need to know the largest average
    // compute dimentions of 
    // y axis = largest average/ 44 (40) -> 50 lines - 6 for info
    // x axis have 120 to work with. can fit each data point. loop set by size of ave list

    printf("                  the usage of %s from %d to %d\n", masterList[mainSearchIndex].word, aveList[0].firstYear, aveList[aveSize-1].lastYear);
    for(int i =0; i<=aveSize; i++)
        printf("-");
    printf("\n");

    for( int j=0; j<40; j++) { 
        printf("\n|");
        for( int i=0; i<aveSize; i++) {
           
            if(aveList[i].average >= (largestAverage/40)*(40-j) )
                    printf("x");
            else
                    printf(" ");
        }
    }
    printf("\n");
    for(int i =0; i<=aveSize; i++)
        printf("-");
    printf("\n");

    int inputYear;
    printf("\n input a year\n" );
    scanf("%d", &inputYear);
    for( int  i=0; i< yearListSize; i++) {
            if ( yearList[i].year == year ) {
                for( int k=0; k<yearList[i].wordListSize; k++) {
                    printf("\n %s", yearList[i].uniqueWordList[k]);
                }
            } 
    }

    return 0;
}
