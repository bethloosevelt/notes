// InfixToPostfix.cpp

//    Convert infix to postfix, using a stack.

// Input characters must be a number 0..9, a space, or an operator: +,-,*,/

//

// Based on ideas from youtube.com/watch?v=vq-nUF0G4fI  with an

// implementation of a stack from CS 251, Fall 2014 at UIC by Dale Reed

// 

/* Running the program looks like:

Enter infix expression: 2+3*4

In postfix that is: 234*+

Done

   And running it again:

Enter infix expression: 2+3*4*5+6

In postfix that is: 234*5*+6+

Done

*/

#include <iostream>   // For basic I/O
#include <cstdlib>
#include <fstream>    // For file input

#include <cstring>    // For string functions

#include <cassert>    // for assertions

using namespace std;

 

// Global Constants

const int MAX_INPUT_SIZE = 81;

 


// Declare structure for a node
struct Node {
    char data;
    Node* pNext;
};   // don't forget the semicolon

void push(char input, Node* &pHead) {

	// Get a new node and add the data
    Node *pTemp = new Node;
    pTemp->data = input;
    pTemp->pNext = NULL;
    
    // Reset pointers depending if this is the first node
    if( pHead != NULL) {
        // Connect into list
        pTemp->pNext = pHead;
    }
    
    // Reset head pointer
    pHead = pTemp;
}

char pop(Node* &stack) {
	Node* temp = stack;
	char op = (*temp).data;
	stack=stack->pNext;
	free(temp);
	return op;
}

// Get weight of an operator, signifying operator precedence.

// When theOperator is '+' or '-' return 1.  When theOperator is '* or '/'

// return 2.

int operatorWeight(char theOperator)

{

int weight = -1;  // set a default

 

switch( theOperator)

{

case '+':
case '-': weight = 1;
          break;
case '*':
case '/': weight = 2;
          break;

}

 

return weight;

}//end operatorWeight(..)

 

 

// Convert infix to postfix, printing out the result as we go

void convertInfixToPostfix( char inputLine[])

{

Node *pTop = NULL;    // create the stack top pointer

char c;                           // current input character

 

// Handle each character from the input

for(int i=0; i<strlen(inputLine); i++) {

 

                 // get next input character

                 c = inputLine[ i];  

   

// Skip spaces, if any

if( c == ' ') continue;

 

// Handle operators

else if(c == '+' || c == '-' || c == '*' || c == '/')

{

// If stored operator on stack (e.g. '*') has higher precedence than

// input operator (e.g. '+') then pop and display stack higher precedence

// operators until this is no longer true.         

while( pTop!=NULL && (operatorWeight(pTop->data) >= operatorWeight(c)) )

{

cout << pop( pTop);

}

push(c, pTop);

}

// else if character is a number, send it to the output

else if( c>='0' && c<='9')

{

cout << c;

}

}//end for( int i...

 

         // Empty remaining lower precedence operators from stack to output

while(pTop != NULL) {
cout << pop(pTop); 
}

}//end convertInfixToPostfix()

 

 

int main()

{

char inputLine[ MAX_INPUT_SIZE];    // input line array

 

cout << "Enter infix expression: ";

cin.getline(inputLine, MAX_INPUT_SIZE);  // read entire line of input

 

cout << "In postfix that is: ";

convertInfixToPostfix(inputLine);

 

cout<<"\nDone \n";

}// end main()