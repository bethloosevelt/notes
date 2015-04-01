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
    char** containedIn;  // a pointer to a list of strings where this string has been found
    int foundInNumberOfFiles; // an integer to keep track of how many files this string is found in { length of containedIn list}
};

// a structure for the nodes in our tree that represents where the files intersect
struct intersectionNode{

    char* fileNameOne;    // name of first file analyzed in the relationship
    char* fileNameTwo;    // name of the file we are analyzing now
    intersectionNode* right;    // apointer to the right hand child node
    intersectionNode* left;     // and for the left
    int count;            // how many strings they have in common
};

stringNode* mainTreeRoot;
intersectionNode* intersectionTreeRoot;
intersectionNode* largestCount;

char** fileList(char* directoryName) {

    char** listOfFiles = (char**)calloc( 3000, sizeof(char*) );
    char* currentFile;     // temp variable to hold pointer and pass it to our pointer list
    struct dirent *aFile;  // curtusey of dirent.h
    int numberOfFiles = 0; // using this as an index, incrimenting after storage to be interpreted as a running count of files in dir
    listOfFiles[numberOfFiles] = NULL;  // as we are reallocing after storage, we will always have an extra slot
                                        // for organization I keep this NULL
    currentFile    = (char*)calloc(30, sizeof(char));

    DIR* directory = opendir( directoryName );

    if (directory != NULL) {

        while ((aFile = readdir( directory)) != NULL) {

            if( strlen(aFile->d_name) > 3 && aFile->d_name[0] != 46) { // if the file/dir is hidden ignore it (hidden = starting with a period)
            
                strcpy(currentFile, aFile->d_name);                    // aFile->d_name is the file name
                listOfFiles[numberOfFiles]  = (char*)calloc(30, sizeof(char));
                strcpy(listOfFiles[numberOfFiles], currentFile);       // store pointer in open slot of our pointer list 
                numberOfFiles++;                                // update file counter to reflect number of files encountered
                listOfFiles[numberOfFiles] = NULL;  // set the last pointer in the list to NULL as stated above
            }
        } 
        closedir( directory);
    }
    return listOfFiles;
}


char* getNextString(FILE* currentFile, char* previousString, int stringSize) {

    char* temp = (char*) calloc(stringSize, sizeof(char)); 
    strcpy(temp, &(previousString[1]));
    free(previousString);
    fscanf(currentFile, " %c", &temp[stringSize]);

    if ( temp[stringSize] == NULL || temp[stringSize] == EOF)
        return NULL;
    return temp;
}

void inOrderTraversal( stringNode * pRoot)
{
    if( pRoot != NULL) {
        inOrderTraversal( pRoot->left);   // recurse down to the left
        cout << pRoot->thisString << " ";        // display contents
        inOrderTraversal( pRoot->right);  // recurse down to the right
    }
}

void dualOrderTraversal( intersectionNode * pRoot)
{
    if( pRoot != NULL) {
        dualOrderTraversal( pRoot->left);   // recurse down to the left
        //cout << " " << pRoot->fileNameOne << " " << pRoot->fileNameTwo << pRoot->count << endl;        // display contents
        if ( pRoot->count > largestCount->count )
            largestCount = pRoot;
        dualOrderTraversal( pRoot->right);  // recurse down to the right
    }
}


stringNode* newNode( char* newString, stringNode* left, stringNode* right, char* currentFileName) {
    
     
    stringNode *temp = new stringNode;
    temp->left = left;
    temp->right = right;
    
    temp->thisString = (char*)calloc(30, sizeof(char));
    strcpy( temp->thisString, newString );
    temp->containedIn = (char**)calloc(1, sizeof(char*) );
    temp->containedIn[0] = (char*)calloc(30, sizeof(char));
    strcpy(temp->containedIn[0], currentFileName);
    temp->foundInNumberOfFiles = 1;
     
    return temp;
}//end newNode(..)


intersectionNode* newDualNode( char* oldFileName, char* currentFileName, intersectionNode* left, intersectionNode* right) {
    
    intersectionNode *temp = new intersectionNode;
    temp->left = left;
    temp->right = right;
    
    temp->fileNameOne = (char*)calloc(25, sizeof(char));
    strcpy( temp->fileNameOne, oldFileName );
    temp->fileNameTwo = (char*)calloc(25, sizeof(char));
    strcpy( temp->fileNameTwo, currentFileName );

    temp->count = 1;
     
    return temp;

}//end newNode(..)


void insertIntoDualTree( intersectionNode* &pRoot, char* oldFileName, char* currentFileName ) {


    if( pRoot == NULL) {
        //cout << oldFileName << endl;
        pRoot = newDualNode( oldFileName, currentFileName, NULL, NULL );
        //printf("merp\n");
    }
    // if both file names match
    else if( (strcmp( oldFileName, pRoot->fileNameOne ) == 0) && (strcmp( currentFileName, pRoot->fileNameTwo ) == 0) ) {
        (pRoot->count)++;
    }
    // if the old one is >
    else if( (strcmp( oldFileName, pRoot->fileNameOne ) > 0) ) {
        // search for insert position for value in the left subtree);
        insertIntoDualTree( pRoot->left, oldFileName, currentFileName );
    }
    // if the old one is <
    else if( (strcmp( oldFileName, pRoot->fileNameOne ) < 0) ) {
        // search for insert position for value in the right subtree);
        insertIntoDualTree( pRoot->right, oldFileName, currentFileName );
    }
    // if the old one matches and the new one is >
    else if( (strcmp( oldFileName, pRoot->fileNameOne ) == 0) && (strcmp( currentFileName, pRoot->fileNameTwo ) > 0)) {
        // search for insert position for value in the left subtree);
        insertIntoDualTree( pRoot->left, oldFileName, currentFileName );
    }
    // if the old one matches and the new one is <
    else if( (strcmp( oldFileName, pRoot->fileNameOne )== 0)  && (strcmp( currentFileName, pRoot->fileNameTwo ) < 0)) {
        // search for insert position for value in the right subtree);
        insertIntoDualTree( pRoot->right, oldFileName, currentFileName );
    }
    else {
        printf("ERROR ERROR NODE NOT FOUND");
    }

    // print ERROR DANGER WILL ROBINSON
}



void insertIntoTree( stringNode* &pRoot, char* string, char* currentFileName) {
    if( pRoot == NULL) {
        pRoot = newNode( string, NULL, NULL, currentFileName);
        //printf("merp\n");
    }
    else if( strcmp( string, pRoot->thisString ) == 0) {
            char* oldFileName = pRoot->containedIn[(pRoot->foundInNumberOfFiles)-1];
           // cout << oldFileName << endl;
            if( strcmp(oldFileName, currentFileName) != 0) {
                pRoot->containedIn = (char**)realloc(pRoot->containedIn, ((pRoot->foundInNumberOfFiles)+1) * sizeof(char*));
                pRoot->containedIn[pRoot->foundInNumberOfFiles] = (char*)calloc(30, sizeof(char));
                strcpy(pRoot->containedIn[pRoot->foundInNumberOfFiles], currentFileName);
                (pRoot->foundInNumberOfFiles)++;
            }
            for ( int i = 0; i< (pRoot->foundInNumberOfFiles); i++) {
                if(strcmp(pRoot->containedIn[i], currentFileName) != 0)
                insertIntoDualTree( intersectionTreeRoot, (pRoot->containedIn)[i], currentFileName );
            }
    }
    else if( strcmp( string, pRoot->thisString ) == 1 ) {
        // search for insert position for value in the left subtree);
        insertIntoTree( pRoot->left, string, currentFileName);
    }
    else {
        // search for insert position for value in the right subtree);
        insertIntoTree( pRoot->right, string, currentFileName);
    }
 
}



int main(int argc, char const *argv[])
{
    intersectionTreeRoot = NULL;
    mainTreeRoot = NULL;
    int pairs;
    int stringSize = 20;
    char dirName[10];
    cout << "Author: Dale Wesa" << endl;
    cout << "Date: 2/20/2015, UIC CS 251 Data StructuresProgram: #2, Like What" << endl;
    cout << "System: g++ on a 2.1 GHz Intel Core i3 Mac, 4GB RAM" << endl;
    cout << "Lab: Thurs 9am" << endl;
    cout << "Running with the medium data set with string length of 20 takes ~100 seconds." << endl;
    cout << "please enter the directory name" << endl;
    cin >> dirName;
    cout << "please enter the string size you want to use" << endl;
    cin >> stringSize;
    cout << "please enter the number of pairs you wish to be displayed" << endl;
    cin >> pairs;
    cout << endl;
    char** listOfFiles = fileList( dirName );
    int j=0;
    char* aString; 
    while (1) {
        if(listOfFiles[j] == NULL)
            break;
       // printf("%s\n", listOfFiles[j]);
        j++;
    }

    char fileDest[25];    
    char* tempString;
    FILE *inFile;    // declare file pointer

    cout << "0" << "%" << endl;
    for ( int i=0; listOfFiles[i] != NULL; i++ ) {
        strcpy(fileDest, "./");
        strcat(fileDest, dirName);
        strcat(fileDest, "/");
        strcat(fileDest, listOfFiles[i]);
        inFile = fopen( fileDest,"r");
        if (inFile == NULL) {
            cout << "ERROR" << endl;
            return -1;
        }
        //cout << fileDest << endl;
        cout << "\e[A";
        cout << "\r";
        cout << i*100/j << "%" << endl;
        aString = (char*)calloc(stringSize+1, sizeof(char));
        for(int i=0; i<stringSize; i++) 
            fscanf(inFile, " %c", &aString[i]);
        
        while (1) {
            aString = getNextString(inFile, aString, stringSize-1);
            if ( aString == NULL )
                break;
            insertIntoTree(mainTreeRoot, aString, fileDest);
        }
        fclose(inFile);
    }
    

    //inOrderTraversal(mainTreeRoot);
    printf("\n\n");
    cout << " " << "   file name" << "\t" << "       file name" << "\t"<< "      intersections" << endl;
    for ( int i=0; i<pairs; i++) {
        largestCount = intersectionTreeRoot;
        dualOrderTraversal( intersectionTreeRoot );
        cout << i+1 << ": " << largestCount->fileNameOne << "\t" << largestCount->fileNameTwo << "\t" << largestCount->count << endl;
        largestCount->count = 0;
    }



    return 0;
}
