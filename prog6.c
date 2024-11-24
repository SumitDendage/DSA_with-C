// Write a function to modify the value of a variable from main()
// Program compiles successfully, but results not achieved
#include <stdio.h>

// fn declaration
void modify(int);

int main()
{
	int c = 20;
	printf("Before modify(), Value in var c is %d",c);  // 20
	modify(c);  // actual argument
	printf("\nAfter modify(), Value in var c is %d",c);  // 20
	return 0;
}

void modify(int c) // formal argument - Any changes made in formal argument are not reflected in
					// actual argument. Hence it is better we keep different names for both these
					// arguments & avoid confusion
{
	c += 5;
	printf("\nIn modify(), value in var c is %d",c);  // 25
}
