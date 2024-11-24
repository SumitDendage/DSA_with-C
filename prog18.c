// Using a self initialised array, determine the maximum no from array
#include <stdio.h>

int main()
{
	int nos[] = {1,-1,0,2,3,6,90,16,5}, max, i, noe;  // noe means no of elements
								// for a self initialised array, SIZE of array is optional
	noe = sizeof(nos) / sizeof(int);  // to know the no of elements in array
	max = nos[0];  // get the 0th element in var max & compare it with rest of the elements
					// If the next element is lesser than max, ignore it. If it is greater than
					// var max, replace max with that value/element from array
	for (i=1;i<noe;i++)
	{
		if (max < nos[i])
			max = nos[i];
	}
	printf("Maximum no from given array is %d",max);
	return 0;
}
