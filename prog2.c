#include <stdio.h>
//#include <info.h>  // error, file info.h not found. If we enclose the header file in <  >, the
					// compiler will look for this header file in absolute path i.e. fixed path
					// i.e. the path in which Dev C++ compiler is installed. However if the
					// header file is a part of current folder i.e. relative path i.e. the path
					// where current executable C file is stored, then use  " "
#include "info.h"  // OK

int main()
{
	printf("My name is Sandeep Shevade");
	my_info();  // fn call
	printf("\nThanks");
	return 0;
}

