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

char* concat(char *s1, char *s2)
{
    char *result = malloc(strlen(s1)+strlen(s2)+1);//+1 for the zero-terminator
    //in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

char* getFileName(){
	
	printf("Enter file name for the scenarion you would like to test: ");
	char* fileName = (char*)malloc(sizeof(char)*20);
	fgets(fileName, 15, stdin);
	// split off the newline from the enter key
	char *pos;
	if ((pos=strchr(fileName, '\n')) != NULL)
	    *pos = '\0';
	return fileName;
}

int main (int argc, char* argv[]) {

	// prompt user for filename
	char* fileName = getFileName();
	printf("filename is: %s", fileName);
	FILE *filePointer = fopen(concat("./", fileName), "r");
	

	char line[100];


	while(fgets(line, 100, filePointer)) {
	    printf("%s\n", line);
    }


	return 0;
}