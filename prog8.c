// Write a function which determines the no. of times it is invoked/called
#include <stdio.h>

// fn declaration
void fn();

int main()
{
	fn();
	fn();
	//count++;  // error, undeclared var "count" (not accessible)
	fn();
	return 0;
}

void fn()
{
	static int count = 1; // Benefit of static var - Scope is local but Life is global
	printf("\nNo of times fn() is called is %d",count);
	count++;
}
