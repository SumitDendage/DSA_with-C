// Write a function to modify the value of a variable from main()
// Program compiled successfully & results not achieved
#include <stdio.h>

// fn declaration
int modify(int);

int main()
{
	int c = 20;
	printf("Before modify(), Value in var c is %d",c);  // 20
	c = modify(c);
	printf("\nAfter modify(), Value in var c is %d",c);  // 25
	return 0;
}

int modify(int x) 
{
	x += 5;
	return x;  // terminate the fn & assign value of x to var c of main()
				// c of main() = x of modify()
}
