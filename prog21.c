// accept a string from user & display it's length
// For length is base is 1 but for position of character, base is 0
#include <stdio.h>
#include <string.h>  // strlen()

int main()
{
	char str[20];
	int len;
	printf("Enter a string :- ");
	gets(str);
	len = strlen(str);
	printf("Length of given string is %d",len);
	return 0;
}
