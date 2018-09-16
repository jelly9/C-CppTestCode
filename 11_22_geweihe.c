#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)

int fun(int n)
{
	if( n/10 )
	{
		return (n%10 + fun(n/10));
	}
	else
	{
		return n;
	}
}

int main()
{
	int n = 0;
	int ret = 0;

	printf("Please intput a number:");
	scanf("%d", &n);
	
	ret = fun(n);
	printf("result = %d\n", ret);


	system("pause");
	return 0;
}