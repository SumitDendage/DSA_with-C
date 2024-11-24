// Write a function which increments the values of 2 int vars of main() by 2 different quantities
// say 3 & 5. Process is known as "Call By Reference/Address". Result achieved.
#include <stdio.h>

// fn declaration
void incr(int *,int *);

int main()
{
	int a = 10, b = 20;
	printf("Before incr(), a = %d and b = %d",a,b);  // 10, 20
	incr(&a,&b);  // passing address of vars a & b
	printf("\nAfter incr(), a = %d and b = %d",a,b);  // 13, 25
	return 0;
}

void incr(int *ptr_a,int *ptr_b)  // pointer variables
{
	*ptr_a += 3;  // Value to which ptr_a is pointing is to be incremented by 3
	*ptr_b += 5;
}

