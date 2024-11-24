// accept the marks of a particular subject for say 5 students & display the average marks
#include <stdio.h>
#define SIZE 5     // This is called as a "preprocessor directive" i.e. before the program is
					// sent for compilation, the preprocessor (program) will substitute word
					// SIZE with 50 everywhere in program & then pass it on to the compiler.
					// The above preprocessor directive is called as "macro expansion".
					// macro in CS means a small program
					
int main()
{
	int marks[SIZE], i, total = 0; // for running total, initialise var to 0 to get rid of
									// garbage value
	float avg;
	printf("Enter the marks of 5 students :- ");
	for (i=0;i<SIZE;i++)
		scanf("%d",&marks[i]);
		
	// calculate total marks
	for (i=0;i<SIZE;i++)
		total += marks[i];   // total = total + marks[i];
		
	avg = (float) total / SIZE;  // typecast to get accuracy. Arithmetical operation between 2
									// int values will produce int result only
	printf("Average marks are %.2f",avg);
	return 0;	
}
