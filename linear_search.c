// Implementation of Linear Search
#include <stdio.h>
#define SIZE 50

struct student
{
	int rollno;
	char name[10];
	float per;
};

// fn declarations
void accept(struct student [],int);  // array of structure & no of records
// search fns are always int functions & return the position of record in an array
int search(struct student [],int,int);  // last argument is the rollno to search

int main()
{
	struct student recs[SIZE];
	int nor, rno, pos;  // nor - no of records to store, rno is rollno
											// to search and pos is position of record in array
	printf("Enter the no. of records :- ");
	scanf("%d",&nor);
	accept(recs,nor);
	printf("Enter the rollno to search :- ");
	scanf("%d",&rno);
	pos = search(recs,nor,rno);
	if (pos == -1)   // -1 is not a valid position in array
		printf("Search Unsuccessful, Record with rollno %d not found",rno);
	else
	{
		printf("Search Successful. Details are\n");
		printf("Rollno - %d, Name - %s, Percent - %.2f",rno,recs[pos].name,recs[pos].per);
		printf("\nRecord found after %d no. of comparisons",pos+1);
	}
	return 0;											 
}

void accept(struct student recs[],int nor)
{
	int i;
	printf("Enter the records\n");
	for (i=0;i<nor;i++)
	{
		printf("Enter the rollno, name & percent :- ");
		scanf("%d %s %f",&recs[i].rollno,recs[i].name,&recs[i].per);  // name is an array and 
										// name of array itself represents address of array.
										// So don't use "&" (address of operator)
	}
}

int search(struct student recs[],int nor,int rno)
{
	int i;
	// search from 1st record till bottom of table (end of array)
	for (i=0;i<nor;i++)
	{
		if (rno == recs[i].rollno)
			return i;  // terminate the function & return the position of record in array		
	}
	// if records in array are exhausted, loop will terminate from top & it means search is
	// unsuccessful
	return -1;	
}


