// for file in directory
//     while ( character != EOF && stringShorterThan(stringSize) )
//         addChar( string )
//     add_node_to_tree(this string) { if string already in tree, incriment(file1, thisFile) }
//     shift string window ->>

// find largest count in the incriment tree
// do above again twice
// report findings

/*
    Dale Wesa
    UIN: 676019303
    CS 251
*/

#include <iostream>
#include <climits>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <dirent.h>
using namespace std;

// a structure for the nodes in our string tree!
struct stringNode{

    char* thisString;     // our data. We will use this to find and store new nodes
    stringNode* right;    // apointer to the right hand child node
    stringNode* left;     // and for the left
    char** cointainedIn;  // a pointer to a list of strings where this string has been found
};

// a structure for the nodes in our tree that represents where the files intersect
struct intersectionNode{

    char* fileNameOne;    // name of first file analyzed in the relationship
    char* fileNameTwo;    // name of the file we are analyzing now
    stringNode* right;    // apointer to the right hand child node
    stringNode* left;     // and for the left
    int count;            // how many strings they have in common
};


char** fileList(char* directoryName) {

    char** listOfFiles = (char**)calloc( 1, sizeof(char*) );
    char* currentFile; 
    struct dirent *aFile;
    int numberOfFiles = 0;
    listOfFiles[numberOfFiles] = NULL;

    DIR* directory = opendir( directoryName );

    if (directory != NULL) {

        while ((aFile = readdir( directory)) != NULL) {

            if( (aFile->d_name)[0] == 46 )  // if the file/dir is hidden ignore it (hidden = starting with a period)
                continue;
            currentFile    = (char*)calloc(30, sizeof(char));
            currentFile = aFile->d_name;                    // aFile->d_name is the file name
            listOfFiles[numberOfFiles] = currentFile;          
            
            numberOfFiles++;
            listOfFiles = (char**)realloc(listOfFiles, (numberOfFiles+1) * sizeof(char*));
            listOfFiles[numberOfFiles] = NULL;
        } 
        closedir( directory);
    }
    return listOfFiles;
}



int main(int argc, char const *argv[])
{
    
    char dirName[10]   = "small";
    char** listOfFiles = fileList( dirName );
    int i=0;
    while (1) {
        if(listOfFiles[i] == NULL)
            break;
        printf("%s\n", listOfFiles[i]);
        i++;
    }

    return 0;
}