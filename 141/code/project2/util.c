/**
* function:  abs_diff(x,y)
*
* returns |x-y|
*/
// return whichever is positive. 
// could have just taken difference and multiplied by -1 if it was negative also
double abs_diff(double x, double y) {
	if (x-y < 0)
    	return y-x;
    else
    	return x-y;

}

/**
* function:  median3(a,b,c)
*
* returns median ("middle value") among a, b and c.
*/
// simple guess and check
// larger data set would require a more elegant solution
// but this I think is acceptable given the context
int median3(int a, int b, int c){
   if ( (a < b && a > c) || (a > b && a < c) )
    	return a;
    if ( (b < a && b > c) || (b > a && b < c) )
    	return b;
    if ( (c < a && c > b) || (c > a && c < b) )
    	return c;
}

/**
* function:  sqrt_floor(n)
*
* returns the "largest integer less than or equal to sqrt(n)"
*
* Examples:
*
*       n       value-returned
*
*       5            2
*       4            2
*       10           3
*       40           6
*       44           6
*
* Note:  your implementation must be self-contained -- i.e., you can't
*        call any library functions (like the math library's sqrt function!).
*/
unsigned  int sqrt_floor(unsigned int n) {
	// your code here!
	// gets highest power of two without going over
	int i=2;
    while ( i*2 < n)
    	i = i*2;
    return i; 
}

/**
* function:  num_ones(n)
*
* returns the number of 1s in the binary representation of n.
*
* Examples:
*
*     The binary representation of 5 is 101; so num_ones(5) would report 2
*
*     num_ones(32) would report 1
*
*     num_ones(15) is 4    (binary representation:  1111)
*
*  Notes:  n is unsigned so
*
*/
int num_ones(unsigned int n) {

	int ones = 0;
    
    // for each bit in the unsigned int
    // if it is anded with 00000...001 and evaluates to true
    // then it is a one. now shift over the bits by one
    for ( int i=0; i < sizeof(n); i++)
    {	
    	if (n & 1)
    		ones++;
    	n = n>>1;
    }
    return ones;
}

