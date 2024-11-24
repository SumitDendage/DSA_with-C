// an eg of strrev() which reverses the contents of a string
#include <stdio.h>
#include <string.h>

int main()
{
	char pwd[10];
	printf("Enter your password :- ");
	gets(pwd);
	strrev(pwd);  // to encrypt the password. There are several encryption techniques out of
					// which this is one.
	printf("Encrypted password is %s",pwd);
	return 0;
}
