// WAP to accept the fullname from user & display it
#include <stdio.h>

int main()
{
	char fullname[30];
	printf("Enter your fullname :- ");
	//scanf("%s",fullname);  // here we are not using "&" address of operator bcoz name of string
						// itself represents the address of string in memory. scanf() here gives
						// a problem. Data after space is considered as data of next variable
						// from scanf()
	gets(fullname);  // gets() means "get string from user". This function was specifically
						// designed for accepting strings from user. So it doesn't require
						// format specifier like %s, %d, %f... unlike scanf() is a versatile
						// command & hence we require format specifier which represents
						// the type of data in a correct fashion
	printf("Your fullname is %s",fullname);
	return 0;
}
