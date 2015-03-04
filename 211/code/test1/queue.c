#include <stdio.h>
#include <stdlib.h>

struct Node {
  float data;
  struct Node *next;
};
typedef struct Node Node;


Node* tail;
Node* initializeQueue(){
	Node* front = (Node*) calloc(1, sizeof(Node));
	front->next = NULL;
	front->data=123456;
	tail = front;
	return front;
}

int isQEmpty(Node* front) {

	if( front->next->next == NULL )
		return 1;
	else
		return 0;
}


int isSEmpty(Node* top) {
	return isQEmpty(top);
}


float front(Node* front) {
	
		return ( (front->next)->data ) ;
}


float top(Node* top) {
	return front(top);
}


void removeFront(Node** front) {
	


		Node* temp = (*front)->next;
		(*front)->next = temp->next;
		free (temp);

}

void pop(Node** top) {
         removeFront(top);
}       


void addToEnd(Node* front, float newData) {
	while( (front->next) != NULL ) {
		//printf("%d\n", front->next);
		front = front->next;
	}
	
	Node* new = (Node*) calloc(1, sizeof(Node));
	new->data = newData;
	new->next = NULL;
	
	front->next = new;
	tail = new;
}


void push (Node** top, float data) {

	addToEnd((*top), data);
	while ( data != front(*top) ) {

		addToEnd( (*top), front((*top)) );
		removeFront(top);
	}
}

int main(int argc, char* argv[]) {

	FILE *src;

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


	Node* head = initializeQueue();
	float data;

	while( !feof(src) ) {
		fscanf(src, "%f", &data);
		push(&head, data);
	} 
	fclose(src);
	printf("finished loading file");
	int i=0;	
	do {
		data = top(head);
		printf("\t%.3f", data);
		if ( i%6 == 0)
			printf("\n");
		i++;
		pop(&head);	
	} while(head->next != tail );



return 0;
}
