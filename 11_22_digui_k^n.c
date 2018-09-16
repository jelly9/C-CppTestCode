#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)

long my_pow(long x, long n){
	if(1 == n)
	{
		return x;
	}
	if(n & 1)
	{
		return my_pow(x*x,n/2) * x;
	}
	else
	{
		return my_pow(x*x,n/2);
	}
}
 
int main()
{
	int k = 0;
	int n = 0;
	int ret = 0;

	printf("请依次输入底数和指数:");
	scanf("%d %d", &k, &n);

	ret = my_pow(k,n);
	printf("%d ^ %d = %d\n", k, n ,ret);

	system("pause");
	return 0;
}