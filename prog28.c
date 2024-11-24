// Define a function "modify()" to alter the contents of a structure variable from main().
// Process is known as "Call By Value". Result not achieved
#include <stdio.h>
#include <string.h>

// typedef command is used to rename any datatype for eg structure. Renamed type is normally
// written in caps (not compulsory). Rename the structure as EMP
/*struct emp
{
	int empid;
	char name[10];
	float salary;
};

typedef struct emp EMP;  */
//typedef long unsigned int LUI;  // another eg to rename existing datatype

typedef struct
{
	int empid;
	char name[10];
	float salary;
} EMP;

// fn declaration
void modify(EMP);

int main()
{
	EMP e = {124,"sumit",50000.50};  // self initialised structure var
	printf("Before modify(), e contains\n");
	printf("Empid = %d,Name = %s,Salary Rs. %.2f",e.empid,e.name,e.salary);
	modify(e);  // e is actual argument
	printf("\nAfter modify(), e contains\n");
	printf("Empid = %d,Name = %s,Salary Rs. %.2f",e.empid,e.name,e.salary);
	return 0;
}

void modify(EMP e)  // e is formal argument
{
	e.empid = 125;
	//e.name = "karan";  // error, string is an array & doesn't support = operator
	strcpy(e.name,"karan");
	e.salary = 75000;
}
