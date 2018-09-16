#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <windows.h>

void swap( int *x, int *y)
{
	*x = *x ^*y;
	*y = *x ^*y;
	*x = *x ^*y;
}

int main()
{
	int a = 0;
	int b = 0;
	printf("Please input two number:");

	scanf("%d %d",&a, &b);
	printf("Before swap: %d  %d\n",a,b);

	swap(&a,&b);
	printf("After  swap: %d  %d\n",a,b);

	system("pause");
	return 0;
}