// WAP to print nos from 1-100 without using a loop & with single printf statement only to
// print single no
// Solution-2, Make main() a recursive fn
#include <stdio.h>

int main()
{
	static int no = 1;  // make a single copy of var no & share it among all the copies of
					// main() created during recursion
	printf("%d ",no);
	no++;
	if (no == 101)
		return 0; // we are returning some no ie 0 bcoz the fn is not void. In general 1 is true
				// & 0 is false. So when we return 0, we are actually not returning any value
				// back. In some compilers like Turbo C, we use void main(). There we will use
				// only return.
		
	main();
	return 0;
} 

