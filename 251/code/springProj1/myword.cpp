
 
#include <iostream>
#include <climits>
#include <string>

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
    shaNode* next;
    shaNode* prev;
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
  if ( a->sha <  *(MyType*)b ) return -1;
  if ( *(MyType*)a == *(MyType*)b ) return 0;
  if ( *(MyType*)a >  *(MyType*)b ) return 1;
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
    shaNode* shaTable = calloc(1, sizeof(shaNode));

    while( fscanf( inFile, "%s %d %d %d", word, &year, &wordCount, &uniqueTextCount) != EOF) {
        // store in as a node in our master structure
        // check if this is a new word
        // if it is a new word { calculate sha, store [sha, word, startingIndex] into hash table IN ORDER of what the sha is}
        // if it is a new word { change the current to the value of new word }
	    if ( index != 0) {
    
            if ( strcmp(word, masterList[ index-1 ].word) != 0) {  // if this is a new word
                                                           // create a new sha node and add it to the list
                sha = hash_str(word);
                shaNode *tempShaNode = new shaNode;
                tempShaNode.sha     = sha;
                tempShaNode.index   = index;

                shaSize++;
                realloc(shaTable, shaSize)

                shaIndex++;
            }
        
        }

        dataPoint.word = (char*)calloc(81, sizeof(char));
        memcpy(dataPoint.word, word, 81);       
        dataPoint.wordCount = wordCount;
        dataPoint.uniqueTextCount = uniqueTextCount;
	
	    masterList[ index ] = dataPoint;

        index++; 

    }

    qsort(shaHead, shaSize, sizeof(unsigned), cmpfunc;
    
    shaNode *playHead = shaHead;
    while ( playHead->next != NULL ) {
        printf( "%u\t%d\t\n", playHead->sha, playHead->index);
        playHead = playHead->next;
    }
    
    printf("\nwow there were %d words in that damn file", words);
    return 0;
}
