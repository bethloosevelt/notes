/**
* Function: print_arb_base
* Parameter:  unsigned int n
* Description:  prints unsigned integer n in an arbitrary base b 
*     where 2 <= b <= 36. Digits are drawn from 0..9a..z in the natural order.
*
* Details:
*    
*    if an invalid base b is passed, an error message is printed
*     and the function returns.
*
*     The digits are printed on a single line from most-significant
*     digit to least.
*
*     Comments:  this is a generalization of procedures for printing
*     bit-level representation, octal, hex, etc.  If b is 16, for example
*     the hex representation is printed.
*
*/
void print_arb_base(unsigned int n, unsigned int b);


/**
*
* Function: is_sorted
* Parameters:
*              integer array a[]
*              integer n specifying length of n
* 
* Description:  returns 1 if array a[0..n-1] is sorted in ascending 
*            order (technically, non-descending order).
*            Returns 0 otherwise
*/
int is_sorted(int a[], int n);

/**
** Function:  sift
**
** Parameters:
**
**     integer array a[]:  the source array -- it is not modified
**     integer array b[]:  the destination array
**     integer n:  the length of arrays a[] and b[]
**     integer p:  the index of partition value or "pivot";
**                 i.e., a[p] is the pivot value.
**
** Description:
**     populates array b[] with the elements of a[] such that:
**     
**        all elements <= a[p] come before all elements > a[p].
**        
**        In other words, the elements of a[] are partitioned into
**        two groups:  those <= a[p] and those > a[p]
**
**        Note:  p may or may not be an element of the given array a[].
**
**        Note:  the relative order of elements on either side of the
**        partition can be arbitrary.
**
**  Return:  index of the start of the 2nd partition -- i.e., the index
**        of the first element in the right partition.
**
**        Note:  The 2nd partition may be empty! In this case, n
**        is returned (i.e., one past the last element of the left side).
**
** Examples:
**
**        a: [2 18 12 9 1 2 8 11 16 3]
**        n: 10
**        p: 3  (so the pivot is a[3]: 9
**
**        after sift (one possibility - left-partition highlighted;
**                    right partition underlined):
**
**             b:  [2 9 1 2 8 3 16 11 12 18]
**
**             returns:  6
**
**        Note:  the ordering produced does may be different from the
**        above, BUT the highlighted values MUST come before the
**        underlined values.  The return value will still be 6.
*/
int sift(int a[], int b[], int n, int p);


/**
* Function:  histogram
* 
* Parameters:
*     unsigned integer array data[]: the "count" array
*     integer n:  the length of array data[], also number of columns
*                 in histogram while displaying.
*
*
* Description:
*     This function will draw an ASCII histogram for n user-entered values
*     A,B,C,D and so on.
*
*     Example: If n = 4, and the input array is {3,7,2,5}, the output should
*     look like this:
*
*        X
*        X
*        X   X
*        X   X
*      X X   X
*      X X X X
*      X X X X
*     ---------
*      A B C D
*
*
*     The following output is WRONG:
* 
*     A: XXX
*     B: XXXXXXX
*     C: XX
*     D: XXXXX
*
*
* Assumptions/Details:
*
*     Each column/bar is labeled with an appropriate capital letter
*        starting from 'A' and continuing left-to-right.
*
*     A histogram is drawn only if n <= 26 -- i.e., only labels
*       'A' to 'Z' are possible.
*     If n is greater than 26, the function should print an error
*       message and return.
*
*     REMEMBER:  characters also have integer interpretations and
*         in ASCII, the integer values for 'A'...'Z' are contiguous
*         and in increasing order.
*/
void histogram(unsigned int data[], int n);




/**
* Function:  num_occ
* Parameters:
*     integer array a[]
*     integer n:  the length of array a[]
*     integer x:  the value being searched for.
*
* Description:   returns the number of occurrences of integer x
*          in array a[].
*/
int num_occ(int data[],  int n, int x);

/**
*
* Function:  num_distinct
* returns the number of distinct values stored in array a.
*
* Parameters:
*
*     a:  array of data
*     n:  length of array a
*
* Description:  returns the number of distinct integers in array a[]
*      
*
*    if a = {1, 2, 3}, all three entries are distinct so 3 is returned.
*
*    if a = {1, 1, 1, 1, 1}, then only one distinct value (1) so 1 is
*          returned.
* RULES:  You may NOT re-order the elements of the array (or modify
* its contents in any way).
*
* 
*/
int num_distinct(int a[], int n);


/**
* returns 1 if a[0..n-1] and b[0..n-1] have the same contents;
*    returns 0 otherwise.
*
* a[] and b[] "have the same contents" when:
*
*      - every integer in a[] is also in b[]
*      - every integer in b[] is also in a[]
*      - all such common values appear exactly the same
*           number of times in both a[] and b[]
*
* examples:
*
*    a = {1, 2, 3}, b = {2, 3, 4}    NO
*    a = {1, 2, 3}; b = {2, 3, 1}    YES
*    a = {1, 2, 2}; b = {2, 2, 1}    YES
*    a = {1, 2, 2}; b = {2, 1, 1}    NO
*    a = {1, 1, 2, 2, 2}; b = {2, 1, 2, 1, 2}    YES
*
* RULES:  You may NOT re-order the elements of the arrays.
*/
int same_contents(int a[], int b[], int n);
