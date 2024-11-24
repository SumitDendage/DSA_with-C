// Write a function which will increment each element of an array from main() by value 1
#include <stdio.h>

// fn declaration
void incr(int [],int);

int main()
{
	int nos[ ] = {10,20,30,40,50}, i, noe;
	noe = sizeof(nos) / sizeof(int);
	printf("Before incr(), nos contains\n");
	for (i=0;i<noe;i++)
		printf("%d ",nos[i]);
	
	incr(nos,noe);
	
	printf("\nAftere incr(), nos contains\n");
	for (i=0;i<noe;i++)
		printf("%d ",nos[i]);	
	
	return 0;
}

void incr(int x[],int noe)// Variables by default are passed as "values" where as "arrays" are always
					// passed as "references". This is bcoz arrays require lot of memory. Hence
					// creating copies of array in called fn may create memory issues & also
					// returning array (after modification) will require lot of processing time.
					// Here "x" is called as an "alias" of nos[ ]. alias is similar to nickname
{
	int i;
	for (i=0;i<noe;i++)
		x[i] += 1;
}
