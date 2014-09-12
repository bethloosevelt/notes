/*
Dale Wesa
UIN: 676019303
practicum
completed: 09/11/2014
*/
#include <stdio.h>
#include <stdlib.h>

// going to need this for setting up our stack
struct Node {
    char data;
    struct Node* next;
};  

int isOpener(char symbol) {
	if ( symbol == '(' || symbol == '{' || symbol == '[' || symbol == '<' ) 
		return 1;
	else 
		return 0;
}

int isCloser(char symbol) {
	if (symbol==')' || symbol=='}' || symbol==']' || symbol=='>') 
		return 1;
	else 
		return 0;
}


struct Node *createNode() {
	// create pointer to memory allocated for a node structure
	struct Node *home;
	home = (struct Node*) malloc( sizeof(struct Node) );
	
	// set values of node to null
	// there is no data yet to store
	// and no other nodes to link to
	home->data = '\0';
	home->next = NULL;

	return home;
}

// used for debugging
// void printStack(struct Node *home) {
// 	while( home != NULL)
// 	{
// 		printf("%c", (*home).data);
// 		home = home->next;
// 	}
// }


struct Node *push(struct Node *stack, char symbol) {
	// create a new bode to store symbol
	struct Node *temp = createNode();
	temp->data = symbol;
	
	// if there is already a node with a value, link the new node
	// so that the existing one is next in sequence (prepend new node)
	// otherwise set next to null, indicating that there
	// is no next node as this new node is the only one at this time
	if ( stack != NULL ) 
		temp->next = stack;
	else
		temp->next = NULL;
	// reset home pointer
	stack = temp; 
	return stack;
}


struct Node *pop(struct Node *home) {
	// move stack pointer to next node in list
	// return new stack pointer
	// this removes the top of the stack
	// should look into freeing the memory though
	// as right now I believe it is still allocated for the newly ignored node
	home=home->next;
 	return home;
}

int corresponds(char opener, char closer) {
	if (opener == '(' && closer == ')')
		return 1;
	if (opener == '{' && closer == '}')
		return 1;
	if (opener == '[' && closer == ']')
		return 1;
	if (opener == '<' && closer == '>')
		return 1;
	else
		return 0;
}

char getCorresponding(char symbol) {

	if (symbol == '(')
		return ')';
	if (symbol == '{')
		return '}';
	if (symbol == '[')
		return ']';
	if (symbol == '<')
		return '>';
	if (symbol == ')')
		return '(';
	if (symbol == '}')
		return '{';
	if (symbol == ']')
		return '[';
	if (symbol == '>')
		return '<';
}

void moveError(int spaces){
	// this is to put our cursor in the right position for printing our error message
	for ( int i=1; i<spaces; ++i )
		printf(" ");
	// print our nice little indicator arrow
	printf("^ ");
}

void broken(char* line, int index, char symbol) {
	// figure out which symbol was supposed to be there
	char corrected = getCorresponding(symbol);

	// first print out the original line
	printf("%s", line);

	// if symbol is an opener, then we were expecting something different
	// at the problem index
	if ( isOpener(symbol) )
	{
		moveError(index);
		printf("Expecting: %c\n", corrected);
	}

	// if symbol is a closer, then we are missing an opener at the problem
	// index
	if ( isCloser(symbol) )
	{
		moveError(index);
		printf("Missing: %c\n", corrected);
	}	
}

int main (void) {
	int MAXSIZE = 300;
	int index = 0;
	char top;

	// initialize a character array to store the line read
	// in from the console
	// read in a string of up to 300 characters (NULL included)
	// storing this beginning at *line
	char* line = (char*) malloc( sizeof(char)*MAXSIZE );
	fgets( line, MAXSIZE, stdin );
	char* lineHome = line;


	struct Node *stackPointer = createNode();
	// while the character in the string isn't a terminating 
	// null character, check whether it is an opening or closing
	// bracket or parenthasis, then incriment the pointer
	for (char symbol = (*line); symbol != '\0'; *line++)
	{
		++index;
		symbol = (*line);
		if ( isOpener(symbol) )
		{	
			stackPointer = push(stackPointer, symbol);
		}

		else
		{
			if ( isCloser(symbol) ) 
			{
					top = (*stackPointer).data;
					// if there is nothing in the stack
					// we have a closing bracket without an opener
					// then send the closer to the broken function 
					// to tell the user there is a missing corresponding opener
					if (top == '\0')
					{
						broken(lineHome, index, symbol);	
						return 1;
					}
					
					// if it is what we expected, pop the opening
					// off of the stack and move along happily
					if (corresponds(top, symbol))
					{	
						stackPointer = pop(stackPointer);
						continue;
					}

					// at this point it must just be the wrong closer
					// so we run our broken function passing the opener 
					// with which the closer was supposed to correspond
					// and our broken function will figure out which symbol 
					// the closer was supposed to be
					else
					{
						broken(lineHome, index, top);
						return 1;
					}
			}
		}
		//printStack(stackPointer);
	}
	// after we make it through, if there is still something in the stack
	// that means there was an opener that was never closed
	top = (*stackPointer).data;
	if (top != '\0')
	{
		broken(lineHome, index, top);
		return -1;
	}
	else
		printf("Balanced Input.\n");
	return 0;
}
