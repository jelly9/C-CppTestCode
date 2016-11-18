#include <stdio.h>
#include <windows.h>

int main()
{
	int i;
	int fib[13] = {1,1};
	for( i = 2; i < 13; i++ )
	{
		fib[i] = fib[i-1] + fib[i-2];
	}
	for( i = 0; i < 13; i++ )
	{
		printf("%d\n", fib[i]);
	}
	system("pause");
	return 0;
}