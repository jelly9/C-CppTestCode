#include <stdio.h>
#include <windows.h>

void *main_ret = NULL;

void bug()
{
	int flag = 16;
	int *p = &flag;
	p += 4;
	p = (int *)main_ret;
	printf("bug\n\n");

	Sleep(5000);
}

int fun( int x, int y)
{
	int c = 8;
	int *p = &x;
	p--;
	main_ret = p;
	*p = (int)bug; 

	printf("fun\n\n");

	return c;
}

int main()
{
	int a = 2;
	int b = 4;

	int ret = fun(a, b);

	printf("you should run here!\n");

	system("pause");
	return 0;
}