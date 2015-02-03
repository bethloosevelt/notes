
 
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
Node masterList[2000000];


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
    int index = 1;  // not zero because we will have our dummy node be the 0th index
    int hashTableSize = 0;
    Node dataPoint = new Node;

    // initialize hash table linked list with a dummy head node
    shaNode *shaHead = new shaNode;
    shaHead->next = NULL;
    shaHead->prev = NULL;
    shaHead->sha = 0;
    shaHead->index = 0;
    shaNode *previousShaNode = shaHead;

    while( fscanf( inFile, "%s %d %d %d", word, &year, &wordCount, &uniqueTextCount) != EOF) {
        // store in as a node in our master structure
        // check if this is a new word
        // if it is a new word { calculate sha, store [sha, word, startingIndex] into hash table IN ORDER of what the sha is}
        // if it is a new word { change the current to the value of new word }
	if ( index != 0)
        	printf("%s\t%s\n", word, masterList[index-1].word );
        if ( strcmp(word, previousNode->word) && index!=0 ) {  // if this is a new word
                                                       // create a new sha node and add it to the list
            sha = hash_str(word);
            shaNode *tempShaNode = new shaNode;
            tempShaNode->sha   = sha;
            tempShaNode->index = index;
            tempShaNode->next = NULL;
            
            previousShaNode->next = tempShaNode;     // set the previous node's next field to the new node
            tempShaNode->prev = previousShaNode;     // set the new nodes prev field to the last node
            previousShaNode = tempShaNode;           // reset the previous node pointer so it reflects the last node
        }


        dataPoint.word = (char*)calloc(81, sizeof(char));
        dataPoint.word = word;            
        dataPoint.wordCount = wordCount;
        dataPoint.uniqueTextCount = uniqueTextCount;
	
	masterList[ index ] = tempData;

        index++; 

    }
     
    shaNode *playHead = shaHead;
    while ( playHead->next != NULL ) {
        printf( "%u\t%d\t\n", playHead->sha, playHead->index);
        playHead = playHead->next;
    }

    return 0;
}
