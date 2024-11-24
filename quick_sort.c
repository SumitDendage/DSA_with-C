// quick sort - implemented using recursion
#include <stdio.h>
#define SIZE 50

// fn declarations
void quick_sort(int [],int,int);

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
		
	quick_sort(nos,0,noe-1);  // pass the array & it's edges for quick_sort
	
	printf("\n\nAfter sorting, elements are\n");
	for (i=0;i<noe;i++)
		printf("%d ",nos[i]);		
		
	return 0;		
}

void quick_sort(int nos[],int l,int h)
{
	int low = l+1, high = h, pivot_el = nos[l], temp; // for swapping
	// write a loop for creating partitions
	while (low <= high)  // if low crosses high, then partition is created
	{
		// keep all smaller elements than pivot_el in left partition
		while (nos[low] < pivot_el)
			low++;
		
		// keep all larger elements than pivot_el in right partition
		while (nos[high] > pivot_el)
			high--;
			
		// on lhs, we have a larger element & on rhs, we have a smaller element
		// So swap than
		if (low < high)	
		{
			temp = nos[low];
			nos[low] = nos[high];
			nos[high] = temp;
			low++;  // release low & high
			high--;
		}
	}
	// now finalise the position of pivot_el by swapping it with element @position nos[high]
	nos[l] = nos[high];
	nos[high] = pivot_el;
	high--;  // pivot_el is now excluded from both partitions
	// now send left & right partitions again for quick_sort using recursion
	if (l < high)
		quick_sort(nos,l,high);
		
	if (low < h)
		quick_sort(nos,low,h);
}







