// WAP to store the data of say 3 emps accepted from user
#include <stdio.h>

// imp - declare the structures globally, so that they are accessible to all functions
struct emp
{
	int empid;
	char name[10];
	float salary;
};

int main()
{
	struct emp recs[3];
	int i;
	printf("Enter the records");
	for (i=0;i<3;i++)
	{
		printf("\nEnter the empid, name & salary of emp no %d :- ",i+1);
		scanf("%d %s %f",&recs[i].empid,recs[i].name,&recs[i].salary);
	}
	printf("Data of 3 emps is");
	printf("\nEmpid\tName\tSalary\n");
	for (i=0;i<3;i++)
		printf("%d\t%s\t%.2f\n",recs[i].empid,recs[i].name,recs[i].salary);
		
	return 0;
}
