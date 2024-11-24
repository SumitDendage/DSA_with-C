// my 1st program with a function to display my personal information
#include <stdio.h>

// fn declaration - optional. required if function is called before it's definition
void my_info();

int main()
{
	printf("My name is Sandeep Shevade");
	my_info();  // fn call
	printf("\nThanks");
	my_info();  // fn called again
	return 0;
}

// fn defn
void my_info()
{
	printf("\nI have done my engineering from COEP");
	printf("\nI have my own comp trg center");
}
