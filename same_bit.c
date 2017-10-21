#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <windows.h>
int main()
{
	int num1 = 0;
	int num2 = 0;
	int a = 0;
	int count = 0;
	printf("please input two numbers :");
	scanf("%d %d", &num1, &num2);

	a = num1^num2;
	while(a)
	{
		a = a & ( a - 1 );
		count++;
	}

	printf("same bit: %d\n",count);
	system("pause");
	return 0;
}