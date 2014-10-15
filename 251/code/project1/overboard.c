/*
Dale Wesa
UIN: 676019303
data structures: CS 251
completed: 09/12/2014
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

// we could make a doubly linked list, 
// since we will be deleting nodes, 
struct Node {
	char identity;
	struct Node* next;
	struct Node* previous;
};

struct Node* deleteNode(struct Node* toBeDeleted) {
	//printf("\ndeleting%d", toBeDeleted);
	toBeDeleted->previous->next = toBeDeleted->next;
	toBeDeleted->next->previous = toBeDeleted->previous;
	struct Node* nextHome = toBeDeleted;
	free(toBeDeleted);
	return nextHome;
}


struct Node* createNode(char passengerType) {
	// create pointer to memory allocated for a node structure
	struct Node* newNode;
	newNode = (struct Node*) malloc( sizeof(struct Node) );
	
	// set values of node to null
	// there is no data yet to store
	// and no other nodes to link to
	newNode->identity = passengerType;
	newNode->next = NULL;
	newNode->previous = NULL;

	return newNode;
}

struct Node* addNode(struct Node* previousNode, char passengerType) {

	// create a new node with all fields NULL
	struct Node* newNode = createNode(passengerType);
	// set the previous node pointer to the existing node in the list
	newNode->previous = previousNode;
	previousNode->next = newNode;
	// return the pointer to this new node, allowing us to then add more new nodes 
	// directly after this
	return newNode;
}


struct Node* createList(FILE* filePointer) {
	
	char identity = getc(filePointer);
	struct Node* headNode = createNode(identity);
	struct Node* previousNode = headNode;
	identity = getc(filePointer);

	while( identity != '\0' && identity != '\n')
	{
		previousNode = addNode(previousNode, identity);
		identity = getc(filePointer);
	}
	headNode->previous = previousNode;
	previousNode->next = headNode;
	return headNode; 
}


void printList(struct Node* head) {
	struct Node* home = head;
	home = home->next;
	while (head != home)
	{	
		home = home->next;
	}
}

int sizeOfList(struct Node* head) {
	struct Node* home = head;
	int count = 1;
	head = head->next;
	while (head != home)
	{
		head = head->next;
		count ++;
	}
	return count;
}

int stillHasAndroids(struct Node* head) {
	for(int i=0; i< sizeOfList(head); ++i)
	{
		if ((*head).identity == 'a' || (*head).identity == 'A')
			return 1;
		head = head->next;
	}
	return 0;
}


char* concat(char *s1, char *s2)
{
    char *result = malloc(strlen(s1)+strlen(s2)+1);
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}


char* getFileName(){
	
	printf("Enter file name for the scenarion you would like to test: ");
	char* fileName = (char*)malloc( sizeof(char)*20);
	fgets(fileName, 20, stdin);
	char *pos;
	// split off the newline from the enter key
	strtok(fileName, "\n");
	return fileName;
}

struct Node* copyList(struct Node* originalHome) {

	char identity = (*originalHome).identity;
	struct Node* copyHome = createNode(identity);
	struct Node* previousNodeCopy = copyHome;
	struct Node* originalHead = originalHome->next;
	identity = (*originalHead).identity;

	while (originalHead != originalHome)
	{
		previousNodeCopy = addNode(previousNodeCopy, identity);
		originalHead = originalHead->next;
		identity = (*originalHead).identity;
	}
	copyHome->previous = previousNodeCopy;
	previousNodeCopy->next = copyHome;
	return copyHome; 

}


struct Node* nextNode(struct Node* startingPoint, int steps) {
	for(int i=0; i<steps; ++i)
		startingPoint = startingPoint->next;
	return startingPoint;
}


int search(struct Node* copy, int counter) {
	struct Node* next = nextNode(copy, counter);
	struct Node* this = next;
	if ( (*this).identity == 'a' || (*this).identity == 'A' )
	{
		//printf("\nfound droid: %d", counter);
		next = deleteNode(this);
		if (!(stillHasAndroids(copy)))
		{
			return 1;
		}
	    return search(next, counter);
	}
	else
	{	
		if (!stillHasAndroids(copy))
		{	
			//printf("no more droids");
			return 1;
		}
	}
	return 0;
}


int main (int argc, char* argv[]) {

	// prompt user for filename
	char* fileName = getFileName();
	FILE *filePointer = fopen(concat("./", fileName), "r");

	struct Node* list = createList(filePointer);
	printf("%d", sizeOfList(list));
	struct Node* copyoflist = copyList(list);
	printList(copyoflist);
	struct Node* copy = NULL;
	for (int counter = 1; counter < sizeOfList(list); counter++)
	{
		copy = copyList(list);
		if ( search(copy, counter) )
		{
			printf("\nThe magic number is: %d\n", counter);
			return 0;	
		}
	}

	printf("\n**there is no solution**\n");
	return 0;
}