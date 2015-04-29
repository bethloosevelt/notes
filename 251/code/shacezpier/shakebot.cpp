#include <iostream>
#include <climits>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <dirent.h>
#include <vector>
#include <fstream>
#include <regex>
using namespace std;


vector<vector<string> > tableOne;
vector<vector<string> > tableTwo;
vector<vector<string> > tableThree;
vector<vector<string> > tableFour;
vector<vector<string> > tableFive;
int collisions = 0;;


#define A 54059 /* a prime */
#define B 76963 /* another prime */
#define C 86969 /* yet another prime */
unsigned hash_str(string s, int tableSize)
{
   unsigned h = 31 /* also prime */;
   int i=0;
   while (i < s.length() ) {
     h = (h * A) ^ ( s.at(i) * B);
     i++;
   }
   return h % tableSize; // or return h % C;
}

vector<string> getWordsFromFile(string filename) {
  vector<string> words;
  // a main string that will hold the contents of a line pulled from a file
  string line;

  // open a file stream from a neighboring file
  ifstream file(filename);
  string word;
  string temp;

  // while we haven't reached the end of our file
  while(file.good()) {
    // get the next line in the file
    getline(file, line);
    regex rgx("\\w+");

    for( sregex_iterator it(line.begin(), line.end(), rgx), it_end; it != it_end; ++it ) {
      //  cout << (*it)[0] << "\n";
      words.push_back((*it)[0]);
      }

    }

    // remove duplicates from vector
    sort( words.begin(), words.end() );
    words.erase( unique( words.begin(), words.end() ), words.end() );

    return words;
}

void insertIntoTable(vector<vector<string> > &table, string word, unsigned index, int &collisions) {

  while(1) {
    if (index >= table.size() ) {
        index = 0;
    }
    if(table.at(index).back() == "") {
       table.at(index).push_back( word );
      return;
    }
    else {
      collisions++;
      index++;
    }
  }
}

void insertIntoTableSquare(vector<vector<string> > &table, string word, unsigned index, int &collisions) {
  int quad=1;
  while(1) {
    if (index >= table.size() ) {
        index = 0;
    }
    if(table.at(index).back() == "") {
       table.at(index).push_back( word );

      return;
    }
    else {
      collisions++;
      index = (index + (quad * quad)) % table.size();
      quad++;
    }
  }
}


void insertIntoTableChain(vector<vector<string> > &table, string word, unsigned index, int &collisions) {

  while(1) {
    if (index >= table.size() ) {
        index = 0;
    }
    if(table.at(index).back() == "") {
       table.at(index).push_back( word );
      return;
    }
    else {
      collisions += table.at(index).size();
      table.at(index).push_back( word );
      return;
    }
  }
}

void hashAndPrint(int tablesize, vector<string> words) {
  cout << tablesize << "\t\t" ;
  vector<string> bucket;
  bucket.push_back("");
  int collisions = 0;
  unsigned hash;

  tableOne.clear();
  tableOne.assign(tablesize, bucket);
  // table one linear
  for ( int i=0; i< words.size(); i++ ) {
    hash = hash_str(words[i], tablesize);
    //cout << words[i] << " : " << hash << endl;
    insertIntoTable(tableOne, words.at(i), hash, collisions);
  }
  cout << collisions << "\t\t";
  tableOne.clear();
  tableOne.assign(tablesize, bucket);

  // table one quadratic
  for ( int i=0; i< words.size(); i++ ) {
    hash = hash_str(words[i], tablesize);
    //cout << words[i] << " : " << hash << endl;
    insertIntoTableSquare(tableOne, words.at(i), hash, collisions);
  }
  cout << collisions << "\t\t\t";
  collisions = 0;
  tableOne.clear();
  tableOne.assign(tablesize, bucket);
  // table one chaining
  for ( int i=0; i< words.size(); i++ ) {
    hash = hash_str(words[i], tablesize);
    //cout << words[i] << " : " << hash << endl;
    insertIntoTableChain(tableOne, words.at(i), hash, collisions);
  }
  cout << collisions << endl;
}

int main(int argc, char const *argv[])
{
  cout << "Author: Dale Wesa" << endl;
  cout << "Date: 4/27/2015, UIC CS 251 Data Structures" << endl;
  cout << "Program: #4, Shakespeare Hashing" << endl;
  cout << "System: g++ on a 2.2 GHz Intel Core i3 Mac, 4GB RAM" << endl;
  cout << "Lab: Thurs 9am" << endl;
  cout << endl;
  cout << "loading file" << endl;
  vector<string> words = getWordsFromFile("will.txt");


  unsigned hash;
  cout << "\t\tCollisions per method" << endl;
  cout << "Table Size\tLinearProbing\tQuadraticProbing\tChaining" << endl;
  int size;
  for ( int i=1; i<6; i++) {
    size = i*10000 + 30000;
      hashAndPrint( size, words);
  }


  return 0;
}
