#include <stdio.h>
#include <windows.h>

void *main_ret = NULL;

void bug()
{
	int flag = 0;
	int *p = &flag;
	p += 4;
	printf("haha\n");
	Sleep(5000);
	*p = main_ret;
	printf("hehe\n");
	Sleep(5000);
}

int fun(int x, int y)
{
	int c = 0xcccccccc;
	int *p = &x;
	printf("%p\n%p\n", &c, &x);

	printf("i am a function.\n");
	p--;
	main_ret = *p;
	*p = (int)bug;


	/*printf("before : %x\n", y);
	p++;
	*p = 0xdddddddd;
	printf("after  : %x\n", y);*/

	return c;
}

int main()
{

	int a = 0xaaaaaaaa;
	int b = 0xbbbbbbbb;
	int ret = fun(a, b);
	_asm
	{
		sub esp, 4
	}

	printf("you should run here.\n");

	system("pause");
	return 0;
}