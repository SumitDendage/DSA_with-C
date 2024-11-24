// Write a function which accepts 3 int nos from main() & returns their sum
#include <stdio.h>

// fn declaration
int calcsum(int,int,int);  // same as fn defn but without names of variables

int main()
{
	// main() is basically meant only to accept data & display the result.
	// It is generally not meant to perform any processing
	int a, b, c, sum;
	printf("Enter 3 whole nos :- ");
	scanf("%d %d %d",&a,&b,&c);
	sum = calcsum(a,b,c);  // a,b,c are called as "actual arguments". Result of calcsum() will
						// be assigned to var sum on LHS
	printf("Sum of given 3 nos is %d",sum);
	return 0;
}

int calcsum(int x,int y,int z)  // x,y,z are "formal arguments". Generally keep the names of 
								// actual & formal arguments different to avoid confusion
{
	// sum = a + b + c;  // error, undeclared vars sum, a, b, c
	int result;
	result = x + y + z;
	return result; // sum of main() = result of calcsum()
}
