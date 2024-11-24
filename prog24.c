// To compare the data of 2 strings
#include <stdio.h>
#include <string.h>

int main()
{
	char str1[20], str2[20];
	printf("Enter str1 :- ");
	gets(str1);
	printf("Enter str2 :- ");
	gets(str2);
	if (strcmp(str1,str2) == 0)  // if result of strcmp() is 0, strings are same
		printf("Given 2 strings are same, considering the case also");
	else
		printf("Given 2 strings are not same, considering the case also");
	
	return 0;	
}
