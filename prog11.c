// WAP to print nos from 1-100 without using a loop & with single printf statement only to
// print single no
// Solution-1, Writing a recursive fn
#include <stdio.h>

// fn declaration
void print_nos(int);

int main()
{
	print_nos(1); // passing a constant value 1 i.e. the starting no to the fn
	return 0;
}

void print_nos(int no)
{
	printf("%d ",no);
	no++;
	if (no == 101)  // condition to mention the stop no
		return;  // terminate the recurssion
		
	print_nos(no);
}
