// this program takes arguments on execution that determine the 
// depth and width of the headings index to be printed
// it's main function is to pring headings with appropriate
// indentation based on those parameters
#include <stdio.h>

// recursive function to print given heading in an outline
// when finished whole outline has been printed
int WIDTH, DEPTH;

void print_headings(int width, int depth)
{   

    
    for ( int i = 0; i < width; i++ ) {
         // print appropriately sized indent
        int indent = DEPTH - depth;
        printf("\n");
        for ( int i=0; i<indent; i++ ) {
            printf("    ");
        }
        printf("Section ");

        if ( depth > 0 ) {
            print_headings(width, depth-1);
        }
    }
}


int main(int argc, char const *argv[])
{
    // if no parameters are passed, raise error
    if ( argc == 1 ) {
        printf("usage: %s <width> <depth> \n", argv[0]);
        return -1;
    }

    // convert character passed into a number for width
    // must resolve pointer before subtracting ascii offset
    WIDTH = (int) *argv[1] - 48;
    // and the same for depth
    DEPTH = (int) *argv[2] - 48;

    // recursive function takes global depth, width left to be printed (width_remaining) of headings
    // as well as a second set to keep track of subsection depth and height
    print_headings(WIDTH, DEPTH);
    

    return 0;
}
