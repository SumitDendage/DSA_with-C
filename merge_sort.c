// merge sort - here we are going to use 2 recursive fns. 1 for partitioning 2. for merging
#include <stdio.h>
#define SIZE 50

// fn declarations
void partition(int [],int,int);
void merge(int [],int,int,int,int);

int main()
{
	int nos[SIZE], noe, i;
	printf("Enter the no of elements :- ");
	scanf("%d",&noe);
	// accept the elements
	printf("Enter the elements\n");
	for (i=0;i<noe;i++)
		scanf("%d",&nos[i]);
		
	system("cls");
	printf("Before sorting, elements are\n");
	for (i=0;i<noe;i++)
		printf("%d ",nos[i]);
		
	partition(nos,0,noe-1);  // pass the left & right positions of array to partition()
							// After no more partitions are possible, this fn only will call
							// merge()
	
	printf("\n\nAfter sorting, elements are\n");
	for (i=0;i<noe;i++)
		printf("%d ",nos[i]);		
		
	return 0;		
}

void partition(int nos[],int left,int right)
{
	int mid = (left+right)/2;
	if (left < right)  // if left = right, it means there is only single element & further 
						// partitions are not possible
	{
		partition(nos,left,mid);    // recursive call - left partition
		partition(nos,mid+1,right);  // recursive call - right partition
		merge(nos,left,mid,mid+1,right); // send left & right partitions for merging	
	}	
}

void merge(int nos[],int l1,int r1,int l2,int r2)
{
	int a, b, c, temp[SIZE];  // vars a & b are used to traverse the left & right partitions
								// respectively. c is used to traverse temp[ ]. temp[ ] is
								// used to store the sorted elements.
	a = l1;
	b = l2;
	c = 0;
	// traverse both the partitions & copy the element which less/small
	// traversal is possible as long as elements exist in the partition
	while (a <= r1 && b <= r2)
	{
		if (nos[a] < nos[b])  // copy the smaller element in temp[ ] @ pos c
		{
			temp[c] = nos[a];
			a++; c++;
		}
		else
		{
			temp[c] = nos[b];
			b++; c++;
		}
	}
	// case-1, left partition is exhausted, copy elements of right partition into temp[ ]
	while (b <= r2)
	{
		temp[c] = nos[b];
		b++; c++;
	}
	// case-2, right partition is exhausted, copy elements of left partition into temp[ ]	
	while (a <= r1)
	{
		temp[c] = nos[a];
		a++; c++;
	}
	c = 0;
	// copy the sorted elements of temp[ ] into original positions in nos[ ]
	// i.e. from left of left partition to right of right partition
	for (a=l1;a<=r2;a++)
	{
		nos[a] = temp[c];
		c++;
	}	
}
