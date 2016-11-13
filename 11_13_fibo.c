#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)

long fibo(int n)
{
	if( n <= 2 )
		return 1;
	
	return fibo( n - 1 ) + fibo( n - 2 );
}
int main()
{
	int a = 0;
	scanf("%d", &a);
	printf("%ld\n", fibo(a));
	system("pause");
	return 0;
}