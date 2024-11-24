// an eg of global variables
#include <stdio.h>

int a = 10, b = 20;    // OK, global vars

// fn declaration
void display();

int main()
{
	int b = 30;  // new local var
	a = 40;  // as there is no local var with name "a", it will modify global var a
	b += 5;  // b = b + 5; 
	printf("In main(), global var a = %d and local var b = %d",a,b);  // 40, 35
	display();  // fn call
	return 0;	
}

// fn defn
void display()
{
	printf("\nIn display(), global vars a = %d and b = %d",a,b);  // 40, 20
}
