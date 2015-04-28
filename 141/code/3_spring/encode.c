
 
#include <stdlib.h>
#include <stdio.h>

#define A 54059 /* a prime */
#define B 76963  // another prime 
#define C 86969 /* yet another prime */

// #define A 2
// #define B 3
// #define C 5

char alphabet[26];


unsigned hash_str(char* s)
{
   unsigned h = 31 /* also prime */;
   while (*s) {
     h = (h * A) ^ (s[0] * B);
     s++;
   }
   return (h%26); // or return h % C;
}


void buildAlphabet(char* name) {

    char letter = 97;

    unsigned offset = hash_str(name);
    for ( int i=0; i<26; i++) {

            alphabet[i] = ((offset+letter-96) + 26) + letter;        
    }
}


int main(int argc, char const *argv[])
{
    char name[10];
    scanf(" %s", name);

    printf("\n%u\n", hash_str(name));
    buildAlphabet(name);

    for ( int i=0; i<26; i++) {
        printf("%c ", alphabet[i]);
    }

    return 0;
}