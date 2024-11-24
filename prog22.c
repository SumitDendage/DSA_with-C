// to copy the contents of source string into target string
#include <stdio.h>
#include <string.h>

int main()
{
	char src[20], tgt[20];
	printf("Enter source string :- ");
	gets(src);
	printf("Enter target string :- ");
	gets(tgt);
	//tgt = src;  // error, string is not a basic type like char, float, int, etc. but a derived
				// type i.e. array & arrays do not support operators like =, ==, <, >, etc.
				// So we need to use special fns
	strcpy(tgt,src);
	// if target string contains some data, it will be overwritten. So after the copying
	// process, source & target strings are identical
	printf("After strcpy(), tgt contains %s",tgt);	
	return 0;	
}
