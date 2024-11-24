// Insertion Sort in ASC order
#include <stdio.h>
#define SIZE 50

// fn declarations
void accept(int [],int);
void ins_sort(int [],int);

int main()
{
	int nos[SIZE], noe;
	printf("Enter the no. of elements :- ");
	scanf("%d",&noe);
	accept(nos,noe);
	ins_sort(nos,noe);
	return 0;
}

void accept(int nos[],int noe)
{
	int i;
	printf("Enter the elements :- ");
	for (i=0;i<noe;i++)
		scanf("%d",&nos[i]);	
}

void ins_sort(int nos[],int noe)
{
	int i, j, key, comp_count = 0, swap_count = 0;
	for (i=1;i<noe;i++)
	{
		key = nos[i];
		// compare the key with values of sorted list
		for (j=i-1;j>=0;j--)
		{
			comp_count++;
			if (key < nos[j])
			{
				nos[j+1] = nos[j];
				swap_count++;
			}
			else
				break;			
		}
		nos[j+1] = key;
		swap_count++;
		printf("\nAfter pass %d, array is ",i);
		for (j=0;j<noe;j++)
			printf("%d ",nos[j]);
	}
	printf("\n\nTotal comparison counter is %d",comp_count);
	printf("\nTotal swap count is %d",swap_count);
}
