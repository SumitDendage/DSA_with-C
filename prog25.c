// an eg of strupr() which returns the string in upper case
// nos or symbols in string remain as they are
#include <stdio.h>
#include <string.h>

int main()
{
	char adr[30];
	printf("Enter your address :- ");
	gets(adr);
	strupr(adr);
	printf("Changed address in upper case is %s",adr);
	return 0;
}
