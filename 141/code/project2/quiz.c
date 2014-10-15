#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


void printMenu() {
	printf("\n1. Addition problem");
	printf("\n2. Subtraction problem");
	printf("\n3. multiplication problem");
	printf("\n4. quit\n");
}

// a case specific get int function. only allows integers that are also menu options
int getInt() {

	int number;
	scanf("%d", &number);

	if ( number > 0 && number <= 4)
		return number;

	while(1)
	{
		printf("Not a valid menu option: ");
		printMenu();
		scanf("%d", &number);
		 if ( number > 0 && number <= 4)
		 	return number;
	}
}


// prints out a question, returns answer to main 
int generateQuestion(int questionType) {
	srand(time(NULL));
	// generate two random numbers from 0->20 
	int arg1 = rand()%101;
	int arg2 = rand()%101;

	// returns the answer of the two random arguments based on question type
	switch (questionType)
	{
		case 1: 
			printf("\n%d + %d = ?\n", arg1, arg2);
			return (arg1 + arg2);
		case 2: 
			printf("\n%d - %d = ?\n", arg1, arg2);
			return (arg1 - arg2);
		case 3: 
			printf("\n%d * %d = ?\n", arg1, arg2);
			return (arg1 * arg2);
	}
}


int main(void) {
	int choice, answer;
	int quit = 0;

	// had to use a couple nested loops here unfortunately. 
	// maybe could break this into a couple different functions
	// simply says that while the user has not quit, generate a question 
	// then let them try to answer
	// gets answer from the generate question function, so main actually has no idea 
	// what the actual question was. just the answer. (generate is the one that actually prints it) 
	while(!quit)
	{
		printMenu();
		choice = getInt();
		if ( choice == 4) 
			quit = 1;
		else
		{
			answer = generateQuestion(choice);
			int answered = 0;
			int attempts = 0;
			
			while (!answered && attempts <= 5)
			{
				scanf("%d", &choice);
				if (choice == answer)
				{
					printf("\nCorrect!\n");
					answered = 1;
				}
				else
				{	if ( attempts <= 4)
						printf("\nincorrect try again\n");
					attempts++;
				}
			}
			if ( !answered )
				printf ( "\nSorry. The correct answer was: %d\n", answer);
		}
	}
return 0;
}
