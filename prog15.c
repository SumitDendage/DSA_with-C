// define a function which accepts the radius of circle from main() & calculates the diameter,
// area and circumference of the circle. Print the results from main()
#include <stdio.h>

// fn declaration
void calc_dac(int,int *,float *,float *);

int main()
{
	int r, d;
	float ac, cc;  // double will also do
	printf("Enter the radius  of circle :- ");
	scanf("%d",&r);
	calc_dac(r,&d,&ac,&cc);  // Mixed Call i.e. Call By Value + Call By Reference
	printf("Radius = %d, Diameter = %d, Area = %.2f, Circumference = %.2f",r,d,ac,cc);
	// By default, the C compiler prints floating point numbers with 6 decimals & for
	// double type upto 12 decimals. %.2f will restrict the decimals to 2 places only.
	// This means that if the 3rd decimal is 5 or more, it will add 1 to the left
	return 0;
}

void calc_dac(int r,int *ptr_d,float *ptr_ac,float *ptr_cc)
{
	*ptr_d = 2 * r;  // r is local variable to calc_dac()
	*ptr_ac = 3.14 * r * r;
	*ptr_cc = 2 * 3.14 * r;	
}
