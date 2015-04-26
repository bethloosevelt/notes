#include <stdio.h>
#include <stdlib.h>    
#include <time.h>       

// functions: get maze parameters  returns int*
// 			  make maze            returns char** { a pointer to a list of character pointers each of which representing a column in the maze }


// initiallize our stack with a dummy node
struct node {
  int x;
  int y;
  struct node *next;
  struct node *previous;
};

typedef struct node stackNode;

// initialize our stack with a dummy node so that we know when we have hit the bottom;
stackNode* stack;
stackNode* top;
int stackSize = 1;   


void initializeStack() {
	stack = (stackNode*)calloc(1, sizeof(stackNode));
	stack->x=-1;
	stack->y=-1; 
	stack->next = NULL;
	stack->previous = NULL;
	top = stack;
}


void push(int x, int y) {

	stackNode* previousNode = top;
	realloc(stack, sizeof(stackNode)*(stackSize+1) );
	stackSize++;
	stackNode* newNode = (stackNode*)calloc(1, sizeof(stackNode));

	// initialize new node
	newNode->next = NULL;
	newNode->previous = previousNode;
	newNode->x = x;
	newNode->y = y;

	// update pointer for previous node
	previousNode->next = newNode;

	stack[stackSize-2] = (*newNode);  // store new node on the stack
	top = newNode;  	              // update top of stack pointer
}


void pop(){

	top = top->previous;
	free(top->next);
	top->next=NULL;
}

void clearStack(){
	
	free(stack);
	initializeStack();
}


stackNode* peek(){
	
	stackNode* topNode = top;  // grab top node from stack
	return topNode;
}


int* getMazeParameters(FILE* src) {
	int* mazeParameters = (int*)calloc(6, sizeof(int) );
	
	int row    = 0;
	int column = 0;
	int startX = 0;
	int startY = 0;
	int endX   = 0;
	int endY   = 0;

	int firstRoundFlag = 1;

	// get rows and columns
	do {
		if( (row < 1 || column < 1) && !firstRoundFlag)  // input validation
			printf( "Invalid: Maze sizes must be greater than 0\n" );  // error message
		else
			if ( !firstRoundFlag )  // if this is not the first time through the loop and the inputs are both > 0
					break;

		firstRoundFlag = 0;  // we have now been through the loop once 

	} while( fscanf(src, " %d %d", &row, &column) );


	firstRoundFlag = 1;
	// get start x and y
	do {
		if( (startX < 1 || startY < 1 || startX > column || startY > row) && !firstRoundFlag )  // input validation
			printf( "Invalid: starting position is outside range %d to %d\n", row, column );      // error message
		else
			if ( !firstRoundFlag )  // if this is not the first time through the loop and the inputs are both > 0
					break;

		firstRoundFlag = 0;  // we have now been through the loop once 

	} while( fscanf(src, " %d %d", &startX, &startY) );


	firstRoundFlag = 1;
	// get start x and y
	do {
		if( (endX < 1 || endY < 1 || endX > column || endY > row || (endX == startX && endY ==startY)) && !firstRoundFlag )  // input validation
			printf( "Invalid: ending position is outside range %d to %d\n", row, column );      // error message
		else
			if ( !firstRoundFlag )  // if this is not the first time through the loop and the inputs are both > 0
					break;

		firstRoundFlag = 0;  // we have now been through the loop once 

	} while( fscanf(src, " %d %d", &endX, &endY) );


	mazeParameters[0] = row; 
	mazeParameters[1] = column;
	mazeParameters[2] = startX;
	mazeParameters[3] = startY;
	mazeParameters[4] = endX;
	mazeParameters[5] = endY;


	return mazeParameters;
}


char** makeMaze(int* mazeParameters) {
	char** maze = (char**)calloc( mazeParameters[0]+2, sizeof(char*) );  // allocate an array of char* the size of how many rows we have specd
																		 // allow 2 extra rows for borders
	for( int i=0; i< mazeParameters[0]+2; i++)	
		maze[i] = (char*)calloc( mazeParameters[1]+2, sizeof(char) );    // for each row, allocate a character array the size of our column count
																		 // allow 2 extra columns for borders
	// build up our borders
	for( int i=0; i< mazeParameters[1]+2; i++)  
		maze[0][i] = '*';					   // fill first row with borders 
	for( int i=0; i< mazeParameters[1]+2; i++)
		maze[ mazeParameters[0]+1 ][i] = '*';  // fill the last row with borders +1 because zero indexed, and 2 extra rows for borders

	for( int i=0; i< mazeParameters[0]+2; i++) {
		maze[i][0] = '*';
		maze[i][ mazeParameters[1]+1 ] = '*';  // for each row fill the first and last slot with a border. +1 because zero indexed, and 2 extra rows for borders
	}

	for (int i = 1; i  <= mazeParameters[0]; i++)
     for (int j = 1; j <= mazeParameters[1]; j++)
       maze[i][j] = '.';

	maze[ mazeParameters[3] ][ mazeParameters[2] ] = 's' ;
	maze[ mazeParameters[5] ][ mazeParameters[4] ] = 'e' ;


	return maze;
}


void printMaze( char** maze, int* mazeParameters) {
	for (int i = 0; i  <= mazeParameters[0]+1; i++) {
    	for (int j = 0; j <= mazeParameters[1]+1; j++)
    		printf("%c ", maze[i][j]);
		printf("\n");
	}
}

void blockMaze( char** maze, int* mazeParameters, FILE* src ) {
	int firstRoundFlag = 1;

	int row    = mazeParameters[0];
	int column = mazeParameters[1];
	int startX = mazeParameters[2];
	int startY = mazeParameters[3];
	int endX   = mazeParameters[4];
	int endY   = mazeParameters[5];
	int X = 0;
	int Y = 0;



	// get start x and y of blocked position and 
	do {
		if( (X < 1 || Y < 1 || X > column || Y > row || (Y==startY && X==startX) || (Y==endY && X==endX)) && !firstRoundFlag )  // input validation
			printf( "Invalid: starting position is outside range %d to %d\n", row, column );      // error message
		else
			if ( !firstRoundFlag )  // if this is not the first time through the loop and the inputs are both > 0
					maze[Y][X]='*';
		firstRoundFlag = 0;  // we have now been through the loop once 

	} while( fscanf(src, " %d %d", &X, &Y) != EOF );

}


stackNode* getAdjacent(int direction) {
	stackNode* pAdj= calloc(1, sizeof(stackNode));
	int topX = top->x;
	int topY = top->y;

	printf("\nDirection: %d\n", direction);

	if(direction == 1){  // up
		pAdj->x = topX;
		pAdj->y = topY - 1;
	}
	if(direction == 2){  // down
		pAdj->x = topX;
		pAdj->y = topY + 1;
	}
	if(direction == 3){  // left
		pAdj->x = topX - 1;
		pAdj->y = topY;
	}
	if(direction == 4){  // right
		pAdj->x = topX+1;
		pAdj->y = topY;
	}
	return pAdj;
}


int noValidMoves(char** maze){

	if( maze[(top->y)+1][(top->x)] == '.')
		return 1;
	if( maze[(top->y-1)][(top->x)] == '.')
		return 1;
	if( maze[(top->y)][(top->x)+1] == '.')
		return 1;
	if( maze[(top->y)][(top->x)-1] == '.')
		return 1;

	return 0;
}

int solveMaze(char** maze, int* mazeParameters) {

	int startX = mazeParameters[2];
	int startY = mazeParameters[3];
	int endX   = mazeParameters[4];
	int endY   = mazeParameters[5];

	push(startX, startY);

	while(1) {

		// grab a random direction { 1: up, 2: down, 3: left, 4: right}
		int direction = rand()%4 + 1;
		// get coordinates of that direction
		stackNode* adjacent = getAdjacent(direction);

		if ( maze[adjacent->y][adjacent->x] == '.' || maze[adjacent->y][adjacent->x] == 'e') {
			push(adjacent->x, adjacent->y);

			if( maze[adjacent->y][adjacent->x] == 'e')
				return 1;
			
			maze[adjacent->y][adjacent->x] = 'v';
		}

		
		printMaze( maze, mazeParameters );
		// printf(" %d %d\n", top->x, top->y);

		if ( !noValidMoves(maze) )
			pop();
		if ( !noValidMoves(maze) && top == stack)
			return 0;		
	}
}


void printStack() {
	printf("\n Stack: \n");
		for(int i=0; i< stackSize-1; i++) 
			printf(" %d %d\n", stack[i].x, stack[i].y);
}

int main(int argc, char* argv[]) {

	FILE *src;
	srand (time(NULL));

	/* verify the proper number of command line arguments were given */
	if (argc < 2) {
	 printf("Usage: %s <input file name>\n", argv[0]);
	 exit(-1);
	}

	/* Try to open the input file. */
	if ( (src = fopen( argv[1], "r" )) == NULL ) {
		printf ( "Can't open input file: %s", argv[1] );
		exit(-1);
	}

	int* mazeParameters = getMazeParameters( src ); // parameters are as follows:
	char** maze = makeMaze( mazeParameters );    	// { 0: rows, 1: columns, 2: starting x, 3: starting y, 4: ending x, 5: ending y } 
	blockMaze( maze, mazeParameters, src );
	initializeStack();


	printf("\n");
	printMaze( maze, mazeParameters );


	int solvable = solveMaze(maze, mazeParameters);

	if( solvable ) {
		printf("\n Solution: \n");
		for(int i=0; i< stackSize-1; i++) 
			printf(" %d %d\n", stack[i].x, stack[i].y);
	}
	else
		printf("\n No Solution \n");



	return 0;
}
