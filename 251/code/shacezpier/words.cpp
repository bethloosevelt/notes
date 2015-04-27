#include <regex>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    string seq = "Some words. And... some punctuation.";
    regex rgx("\\w+");

    for( sregex_iterator it(seq.begin(), seq.end(), rgx), it_end; it != it_end; ++it )
        cout << (*it)[0] << "\n";
}
