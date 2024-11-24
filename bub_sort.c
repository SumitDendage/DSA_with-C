// Implementation of Improvised Bubble Sort Algorithm for an array of int values
#include <stdio.h>
#define SIZE 50

// fn declarations
void accept(int [],int);
void bub_sort(int [],int);

int main()
{
	int nos[SIZE], noe;
	printf("Enter the no. of elements :- ");
	scanf("%d",&noe);
	accept(nos,noe);
	bub_sort(nos,noe);
	return 0;
}

void accept(int nos[],int noe)
{
	int i;
	printf("Enter the elements :- ");
	for (i=0;i<noe;i++)
		scanf("%d",&nos[i]);	
}

void bub_sort(int nos[],int noe)
{
	int i, j, temp, comp_count = 0, flag, swap_count = 0;  
								// flag is not a keyword but a name assigned to a
								// special var which is used to test the success of a process.
								// If the flag value is 0, it means the process is unsuccessful.
								// If the flag value is 1, it means the process is successful.
	// outer loop
	for (i=1;i<noe;i++)
	{
		flag = 0;  // before the comparison begins, initialise flag to 0
		// inner loop for comparing element
		for (j=0;j<noe-i;j++)
		{
			comp_count++;
			if (nos[j] > nos[j+1])
			{
				// swap the elements
				temp = nos[j];
				nos[j] = nos[j+1];
				nos[j+1] = temp;
				swap_count += 3;
				flag = 1;   // the data is not in order & we need to compare the elements again				
			}
		}
		printf("\nAfter pass %d elements are ",i);
		for (j=0;j<noe;j++)
			printf("%d ",nos[j]);	
			
		if (!flag)   // if (flag == 0)  // swapping did not take place, ! negation operator which
			break;							// reverses the condition. If value of flag is 0,
											// !flag is !0 i.e. 1 (true) & loop terminates.
										  // break will terminate the outer loop
				
	}  // end of outer loop

	printf("\nNo of comparisons are %d",comp_count);
	printf("\nNo of swappings are %d",swap_count);	// lesser the swappings, more efficient
											// is the program
}
