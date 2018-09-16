#include <stdio.h>
#include <windows.h>

int main()
{
	int i = 0;
	
	for(i = 0; i < 10; i++)
	{
		static int n = 1;
		printf("%d\n", n);
		n++;
	}

	system("pause");
	return 0;
}










//#include <stdio.h>
//#include <windows.h>
//
//extern void fun2();
//
//int main()
//{
//	
//	fun2();
//
//	system("pause");
//	return 0;
//}