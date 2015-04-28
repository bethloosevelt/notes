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


vector<string> tableOne;
vector<string> tableTwo;
vector<string> tableThree;
vector<string> tableFour;
vector<string> tableFive;
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

void insertIntoTable(vector<string> &table, string word, unsigned index, int &collisions) {

  while(1) {
    if (index == table.size() ) {
        index = 0;
    }
    if(table.at(index) == "") {
      table.at(index) = word;
      return;
    }
    else {
      collisions++;
      index++;
    }
  }
}

int main(int argc, char const *argv[])
{
  vector<string> words = getWordsFromFile("will.txt");
  string empty = "";
  tableOne.assign(37141, empty);
  tableTwo.assign(40000, empty);
  tableThree.assign(50000, empty);
  tableFour.assign(60000, empty);
  tableFive.assign(70000, empty);

  cout << words.size() << endl;
  // vector hashTable = new vector();
  // hashTable.reserve(words.size());
  unsigned hash;
  unsigned size = words.size();
  cout << size << endl;

  for ( int i=0; i< words.size(); i++ ) {
    hash = hash_str(words[i], size);
    //cout << words[i] << " : " << hash << endl;
    insertIntoTable(tableOne, words.at(i), hash, collisions);
  }
  cout << collisions;
  return 0;
}
