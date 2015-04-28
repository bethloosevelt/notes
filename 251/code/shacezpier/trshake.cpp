#include <iostream>
#include <climits>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <dirent.h>
#include <vector>
#include <fstream>
#include <algorithm>
#include <regex>
using namespace std;


struct node{

    node* alphabet[26];
    bool isWord;
  };

node* head = new node;

int total;


bool contains_number(string c)
{
    return (c.find_first_of("0123456789-_") != string::npos);
}

void initializeHead(node *anode) {
  for(int i=0; i<26; i++) {
    (anode->alphabet)[i] = NULL;
    anode->isWord = false;
  }
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
      word = (*it)[0];
      // if it has a number skip it
      if(contains_number(word))
        continue;

      transform(word.begin(), word.end(), word.begin(), ::tolower);
      words.push_back(word);
      }

    }

    // remove duplicates from vector
    sort( words.begin(), words.end() );
    words.erase( unique( words.begin(), words.end() ), words.end() );

    return words;
}

int charToU(char s) {
  return ((int) s) - 97;
}

void addToTrie(node* current, string word) {


  for (int i=0; i< word.length(); i++) {

      if( (current->alphabet)[charToU((char)word.at(i))] == NULL ) {
        //  cout << "making new node" << endl;
          (current->alphabet)[charToU((char)word.at(i))] = new node;
          total++;
          initializeHead((current->alphabet)[charToU((char)word.at(i))]);
      }

      if ( i+1 == word.length()) {
         (current->alphabet)[charToU((char)word.at(i))]->isWord = true;
        //  cout << "added to trie" << endl;
          return;
        }

      current =  (current->alphabet)[charToU((char)word.at(i))];
  }
}

bool findInTrie(node* current, string word) {

  for (int i=0; i< word.length(); i++) {

      if( (current->alphabet)[charToU((char)word.at(i))] == NULL ) {
          return false;
      }

      if ( i+1 == word.length()) {
          return true;
        }

      current =  (current->alphabet)[charToU((char)word.at(i))];
  }

  return false;
}

int main(int argc, char const *argv[])
{

  cout << "Author: Dale Wesa" << endl;
  cout << "Date: 4/27/2015, UIC CS 251 Data Structures" << endl;
  cout << "Program: #5, Shakespeare Trie" << endl;
  cout << "System: g++ on a 2.2 GHz Intel Core i3 Mac, 4GB RAM" << endl;
  cout << "Lab: Thurs 9am" << endl;
  cout << endl;

  total = 0;
  initializeHead(head);

  cout << "loading file" << endl;
  vector<string> words = getWordsFromFile("will.txt");


  cout << "building trie" << endl;

  //cout << words.size() << endl;
  // vector hashTable = new vector();
  // hashTable.reserve(words.size());
  unsigned hash;
  unsigned size = words.size();
  //cout << size << endl;
  //
  // for ( int i=0; i< 26; i++ ) {
  //   if ( (head->alphabet)[i] == NULL)
  //   cout << "good" << endl;
  // }

  for (int i=0; i<words.size(); i++) {
    addToTrie(head, words[i]);
  }

  cout << "created " << total << " Trie nodes" << endl;
  cout << "begin searching (terms will be converted to lowercase)" << endl << "or enter x to exit" << endl;

  string searchFor;
  while(1) {
    cin >> searchFor;
    transform(searchFor.begin(), searchFor.end(), searchFor.begin(), ::tolower);
    if( findInTrie(head, searchFor) )
      cout << "yes " << searchFor << " is found" << endl;
    else
      cout << "no " << searchFor << " is not found" << endl;
    if (searchFor == "x")
      return 0;
  }

  return 0;
}
