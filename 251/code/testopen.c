#include <stdlib.h>
#include <stdio.h>


int main(void) {

fstream file;
fopen("scenario.txt", file);

char c = getc(*file);

printf("%c", c);

return 0;
}
