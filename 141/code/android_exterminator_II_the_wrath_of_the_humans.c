// a program to circle through a linked list, kicking out "androids" along the way. 
// the goal is to find a magic number that removes all androids, leaving only humans. 
// WOW! SPACE!

#include <stdio.h>
#include <stdlib.h>

// functions needed

char * getFileName()

char * loadScenario(filename)

int findCylons(list)

int matin(void) {
	printf("Scenario: <file name>\n");
	
	filename = getFileName();
	list = loadScenario(filename);
	found =	findCylons(list);
	if(found)
		printf("\nChoose the number %d to kick out all cylons. Long live humanity.", number);
	else
		printf("\nHuman blood must be spilled this day.");
	
	return 0;
}
