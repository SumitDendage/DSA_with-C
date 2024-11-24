// to join the contents of source string to target string
#include <stdio.h>
#include <string.h>

int main()
{
	char src[20], tgt[40];  // target string should have more length than source bcoz it has
								// to accomodate it's contents as well as contents of src string
	printf("Enter source string :- ");
	gets(src);
	printf("Enter target string :- ");
	gets(tgt);
	strcat(tgt,src);
	printf("After strcat(), tgt contains %s",tgt);	
	return 0;	
}
