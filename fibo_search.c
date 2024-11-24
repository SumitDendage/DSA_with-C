// Fibonacci Search for searching the record of a student on the basis of rollno
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
int search(struct student [],int,int);  // -- do -- and rollno to search

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
	pos = search(recs,nor,rno);
	if (pos == -1)
		printf("Record with rollno %d not found",rno);
	else
	{
		printf("Search Successful. Details of record are");
		printf("\nRollno - %d, Name - %s, Percent - %.2f",rno,recs[pos].name,recs[pos].per);
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

int search(struct student recs[],int nor,int rno)
{
	int f1 = 0, f2 = 1, index, prev_index = 0;  // f1 - current term, f2 - next term
	// logic is that initially we search for a record @ position using fibo series no. Later
	// we add that fibo series no to another no from same series to narrow the search.
	// This is normally required when we want to search in 1/3rd part of array.
	while (f2 < nor)
	{
		f2 = f1 + f2;
		f1 = f2 - f1;
	}
	// now bring the fibo nos back by single position
	f1 = f2 - f1;
	f2 = f2 - f1;
	while (f2 >= 0)
	{
		index = prev_index + f2;
		comp_count++;
		if (rno == recs[index].rollno)
			return index;
		else if (rno < recs[index].rollno || index >= nor) // search in 2/3 rd portion on left
		{
			// bring f1 and f2 to the left by single position
			f1 = f2 - f1;
			f2 = f2 - f1;
		}
		else  //  look in right portion which is 1/3 ed
		{
			// bring f1 and f2 to the left by 2 positions
			f2 = f2 - f1;
			f1 = f1 - f2;
			prev_index = index;			
		}
	}
	return -1;   // search is unsuccessful
}
