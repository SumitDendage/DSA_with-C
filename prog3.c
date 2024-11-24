// An eg in which the called function becomes the calling function for some other function
#include <stdio.h>

// fn declarations
void street(), college();

int main()
{
	printf("I'm in my home");
	street();
	printf("\nI'm back home");
	college();
	return 0;
}

void street()
{
	printf("\nI'm on my way to college");
	college();
	printf("\nI'm on my way to home");
}

void college()
{
	printf("\nI'm in my college attending lectures");
}
