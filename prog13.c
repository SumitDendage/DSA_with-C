// Write a function which increments the values of 2 int vars of main() by 2 different quantities
// say 3 & 5. Process is known as "Call By Value". Result not achieved.
#include <stdio.h>

// fn declaration
void incr(int,int);

int main()
{
	int a = 10, b = 20;
	printf("Before incr(), a = %d and b = %d",a,b);  // 10, 20
	incr(a,b);  // actual arguments
	printf("\nAfter incr(), a = %d and b = %d",a,b);  // 10, 20
	return 0;
}

void incr(int a,int b)  // formal arguments
{
	a += 3;  // making changes in formal arguments is not reflected in actual arguments
	b += 5;
}

