#include <stdio.h>

/*
* Return 1 when x can be represented as an n-bit, 2’s complement number; 0 otherwise 
* Assume 1 <= n <= w
* Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
* Legal ops: ! ~ & ^ | + << >> 
*/
int fits_bits(int x, int n) {

	if(~(x-1)>>(n+1) == 0)
		return 1;
	else
		return 0;

}

/*
* reverseBytes - reverse the bytes of x 
 * Example: reverseBytes(0x01020304) = 0x04030201 
 * Legal ops: ! ~ & ^ | + << >> 
 */ 
int reverseBytes(int x) {
	return(x << 24)|((x >> 8 & 0xFF) << 16)|((x >> 16 & 0xFF) << 8)|(x >> 24);
}


int main(int argc, char* argv[]) {

	// for ( int i=0; i<25; ++i )
	// {
	// 	printf("Welcome to CS 261");
	// }

	if (fits_bits(5,3))
		printf("this wasn't intended to be true\n");

	if (fits_bits(-4, 3))
		printf("this was intended to be true\n");
	int number = 43;
	printf("%x\n", number );
	number = reverseBytes(number);
	printf("%x\n", number );

	return 0;


}



// 16 assembly instructions
// i is stored in -4(%rbp)
// our string is stored in %edi

// $7 = 14
// (gdb) continue
// Continuing.

// Breakpoint 1, main (argc=1, argv=0x7fffffffddc8) at hwk2.c:7
// 7			printf("Welcome to CS 261");
// (gdb) print i
// $8 = 15
// (gdb) info registers
// rax            0x11	17
// rbx            0x0	0
// rcx            0x7420656d6f636c65	8367799628349008997
// rdx            0x7ffff7dd59e0	140737351866848
// rsi            0x400605	4195845
// rdi            0x7ffff7ff70ff	140737354100991
// rbp            0x7fffffffdce0	0x7fffffffdce0
// rsp            0x7fffffffdcc0	0x7fffffffdcc0
// r8             0x313632205343206f	3546076871018094703
// r9             0x0	0
// r10            0x7ffff7fcc740	140737353926464
// r11            0x246	582
// r12            0x400440	4195392
// r13            0x7fffffffddc0	140737488346560
// r14            0x0	0
// r15            0x0	0
// rip            0x400545	0x400545 <main+24>
// eflags         0x283	[ CF SF IF ]
// cs             0x33	51
// ss             0x2b	43
// ds             0x0	0
// es             0x0	0
// fs             0x0	0
