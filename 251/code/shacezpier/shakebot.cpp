#include <iostream>
#include <climits>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <dirent.h>
#include <vector>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[])
{
  vector<string> words;
  // a delimiter for the space between words in a line
  string delimiter = " ";
  // a main string that will hold the contents of a line pulled from a file
  string line;

  // open a file stream from a neighboring file
  ifstream file("will.txt");
  string word;
  string temp;
  int wordCount = 0;

  // while we haven't reached the end of our file
  while(file.good()) {
    // get the next line in the file
    getline(file, line);
    while ( line.length() > 0 ) {
      // if there is a space in the line still
      if ( line.find(delimiter) < 1000 ) {
        // grab the beginning of the line until the space and store it as a word
        word = line.substr(0, line.find(delimiter));
        // now chop the line so it is the remaining characters after the space
        line = line.substr(line.find(delimiter)+1, line.length());
        // do something with the word
        wordCount++;
        cout << word << endl;
      }
      else {
        // if there is no space in the line, make the line a word
        word = line;
        // make the line an empty string
        line = line.substr(line.length(), line.length());
        // do something with the word
        wordCount++;
        cout << word << endl;
      }
    }

  }
  cout << wordCount << endl;
  return 0;
}
