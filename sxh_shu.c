#include <stdio.h>

int main()
{
	int i = 0;
	int m = 0;
	int n = 0;
	int sum = 0;
	int count = 0;
	for( i = 1; i<1000; i++)
	{
		n = i;
		sum = 0;
		while(n)
		{
			m = n%10;
			n /= 10;
			sum += m*m*m;
		}
		if( sum == i )
		{
			count++;
			printf("%d  ", sum);
		}
	}
	printf("count = %d", count);
	return 0;
}