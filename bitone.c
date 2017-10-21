#include <stdio.h>



//1/1-1/2
int main()
{
	double i = 0.0;
	double sign = 1.0;
	double sum = 0.0;
	for( i = 1; i<=100; i++)
	{
		sum = sum + sign/i;
		sign = -sign;
	}
    printf("1/1-1/2+1/3...-1/100 = %lf", sum);
	return 0;
}