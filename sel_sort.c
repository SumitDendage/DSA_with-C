// Selection Sort - ASC order
#include <stdio.h>
#define SIZE 50

// fn declarations
void accept(int [],int);
void sel_sort(int [],int);  // passing reference to array & no of elements

int main()
{
	int nos[SIZE], noe;
	printf("Enter the no. of elements :- ");
	scanf("%d",&noe);
	accept(nos,noe);
	sel_sort(nos,noe);
	return 0;
}

void accept(int nos[],int noe)
{
	int i;
	printf("Enter the elements :- ");
	for (i=0;i<noe;i++)
		scanf("%d",&nos[i]);
}

void sel_sort(int nos[],int noe)
{
	int i, j, pos_min, comp_count = 0, swap_count = 0, temp, flag;
	for (i=0;i<noe-1;i++)
	{
		pos_min = i;
		// compare one by one element & look for min element
		for (j=i+1;j<noe;j++)
		{
			comp_count++;
			if (nos[j] < nos[pos_min])
				pos_min = j;
		}
		// It is confirmed that element @ pos_min is the smallest element
		// finalise it's position
		if (pos_min != i)
		{
			temp = nos[pos_min];
			nos[pos_min] = nos[i];
			nos[i] = temp;
			swap_count += 3;
		}
		printf("\nAfter Pass %d, elements are ",i+1);
		for (j=0;j<noe;j++)
			printf("%d ",nos[j]);
	}  // end of outer loop
	printf("\nTotal no of comparisons are %d",comp_count);
	printf("\nTotal no of swappings are %d",swap_count);
}
