#include <stdio.h>

int main()
{
	int i = 0;
	int n = 2;
	int Sn = 0;
	int j = 0;
	printf("Please input: ");
	scanf("%d",&j);
	for( i = 0; i<j; i++)
	{
		Sn += n;
		n = 10*n+2;
		
	}
	printf("%d\n", Sn);
	return 0;
}