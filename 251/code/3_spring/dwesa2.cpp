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
#include <string>
#include <vector>
#include <dirent.h>
#include <fstream>

using namespace std;

typedef struct master_list_node {

    int* node_connections;
    int  node_degree;

} master_list_node;

// lets keep this global for simplicities sake
master_list_node* master_list;


void readInFile( char fileName[10]) {

    int graph_size;
    string num_string = "";

    int numbers[100];
    int index;

    int number;
    ifstream fp (fileName);
    string line;
    fscanf(fp, )
}


int main(int argc, char const *argv[])
{
    char fileName[10];
    cout << "Author: Dale Wesa" << endl;
    cout << "Date: 2/20/2015, UIC CS 251 Data StructuresProgram: #2, Like What" << endl;
    cout << "System: g++ on a 2.1 GHz Intel Core i3 Mac, 4GB RAM" << endl;
    cout << "Lab: Thurs 9am" << endl;
    cout << "please enter the directory name" << endl;
    cin >> fileName;
    cout << endl;


    readInFile(fileName);
    return 0;
}