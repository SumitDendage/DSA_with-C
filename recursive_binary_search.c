// Binary Search for searching the record of a student on the basis of rollno Using Recursion
#include <stdio.h>
#define SIZE 50

struct student
{
	int rollno;
	char name[10];
	float per;	
};

// fn declarations
void accept(struct student [],int);  // array of structures, no of records
int search(struct student [],int,int,int,int);  // -- do -- and top, bottom, rollno to search

// imp - declare comp_count globally. WHY? The search() will return the position of record like
// in linear search. However the position of record is independent of no of comparisons. Also
// the search() cannot return multiple values. So declare comp_count globally in which search()
// will modify it and main() will print it.
int comp_count = 0;

int main()
{
	struct student recs[SIZE];
	int nor, rno, pos;
	printf("Enter the no of records :- ");
	scanf("%d",&nor);
	accept(recs,nor);
	printf("Enter the rollno to search :- ");
	scanf("%d",&rno);
	pos = search(recs,nor,0,nor-1,rno);
	if (pos == -1)
		printf("Record with rollno %d not found",rno);
	else
	{
		printf("Search Successful. Details of record are");
		printf("\nRollno - %d, Name - %s, Percent - %.2f",rno,recs[pos].name,recs[pos].per);
		// In binary search, like linear search, the position is not an indicator for the
		// no. of comparisons
		printf("\nRecord found after %d no of comparisons",comp_count);
	}
	return 0;	
}

void accept(struct student recs[],int nor)
{
	int i;
	printf("Enter the records of students in ASC order by rollno\n");
	for (i=0;i<nor;i++)
	{
		printf("Enter the rollno, name & percent :- ");
		scanf("%d %s %f",&recs[i].rollno,recs[i].name,&recs[i].per);
	}
}

int search(struct student recs[],int nor,int top,int bottom,int rno)
{
	int mid;
	mid = (top + bottom) / 2;
	comp_count++;
	if (rno == recs[mid].rollno)
		return mid;
	else if (rno > recs[mid].rollno)  // search bottom half
		top = mid + 1;
	else
		bottom = mid - 1;
		  
	if (top <= bottom)   // loop condition
		search(recs,nor,top,bottom,rno);   // recursive call
	else
		return -1;   // search unsuccessful, terminate recursion
}
