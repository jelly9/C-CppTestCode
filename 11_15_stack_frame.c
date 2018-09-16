c#include <stdio.h>
#include <windows.h>

void *main_ret = NULL;

void bug()
{
	int flag = 0;
	int *p = &flag;
	p += 4;

	printf("i am a bug\n");
	printf("flag:%p\np   :%p\n\n", &flag, p);

	Sleep(3000);

	*p = (int)main_ret;
	printf("returning...\n\n");
	Sleep(3000);
}

int fun(int x, int y)
{
	int c = 0xcccccccc;
	/*int *p = &x;
	p--;

	printf("i am a function.\n");
	printf("fun:%p\ny  :%p\nx  :%p\nc  :%p\nret:%p\n\n", fun, &y, &x, &c, p);
	
	
	main_ret = *p;
	*p = (int)bug;
*/
	return c;
}

int main()
{

	int a = 0xaaaaaaaa;
	int b = 0xbbbbbbbb;
	int ret = 0;

	printf("i am a main\n\n");

	ret = fun(a, b);


	printf("you should run here.\n\n");

	system("pause");
	return 0;
}













