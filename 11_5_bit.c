#include <stdio.h>
#include <windows.h>

int main()
{

	unsigned char i = 0;
	for(i = 0; i<=255; i++)
	{
		printf("%d\n", i);
		Sleep(10);
	}
	/*int i = 0;
	char a[1000];
	for(i = 0; i<257; i++)
	{
		a[i] = -1-i;
		printf("%d\n", a[i]);
	}
	printf("len = %d\n", strlen(a));*/

	system("pause");
	return 0;
}
