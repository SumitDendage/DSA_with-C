// Write a function which determines the no. of times it is invoked/called
// Using "global var" count. This solution gives the reqd result but is not acceptable by
// programmers bcoz "global vars are succeptible (prone to attack/vulnerable) & hence any function can
// access it & modify, to give wrong results"
#include <stdio.h>

int count = 1;   // global var

// fn declaration
void fn();

int main()
{
	fn();
	fn();
	count++;  // no error, but will lead to wrong results
	fn();
	return 0;
}

void fn()
{
	printf("\nNo of times fn() is called is %d",count);
	count++;
}
