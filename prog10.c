// Write a recursive function to determine the factorial value of any given +ve whole no
#include <stdio.h>

// fn declaration
int fact(int);

int main()
{
	int no, fv;
	printf("Enter the no :- ");
	scanf("%d",&no);
	fv = fact(no);
	printf("Factorial value of no %d is %d",no,fv);
	return 0;
}

// fn defn
int fact(int x)
{
	int y;
	if (x == 1)
		return 1;   // factorial value of 1 is 1
	
	y = x * fact(x-1);
	return y;   // fv of main() = y of fact()
}
