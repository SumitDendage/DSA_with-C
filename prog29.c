// Define a function "modify()" to alter the contents of a structure variable from main().
// Process is known as "Call By Reference/Address". Result achieved
#include <stdio.h>
#include <string.h>

typedef struct
{
	int empid;
	char name[10];
	float salary;
} EMP;

// fn declaration
void modify(EMP *);

int main()
{
	EMP e = {124,"sumit",50000.50};  // self initialised structure var
	printf("Before modify(), e contains\n");
	printf("Empid = %d,Name = %s,Salary Rs. %.2f",e.empid,e.name,e.salary);
	modify(&e);  
	printf("\nAfter modify(), e contains\n");
	printf("Empid = %d,Name = %s,Salary Rs. %.2f",e.empid,e.name,e.salary);
	return 0;
}

void modify(EMP *ptr_e)
{
	//ptr_e.empid = 125; // error, with pointer to structures, we have to use -> operator & not
						// . (dot) operator
	ptr_e->empid = 125;
	strcpy(ptr_e->name,"karan");
	ptr_e->salary = 75000;
}
