//#include <stdio.h>
//#include <windows.h>
//
//
//void mystrcpy(char *dest, const char *src)
//{
//	while( *dest++ = *src++);
//	//return dest;
//}
//
//int main()
//{
//	char str1[10] ;
//	char str2[] = "Hello bit!";
//	mystrcpy(str1, str2);
//	printf("%s\n", str1);
//	system("pause");
//	return 0;
//}

#include <stdio.h>

int mystrlen(char *str )
{
	int len = 0;
	while(str)
	{
		printf("hhh\n");
		len++;
		len++;
	}
	return len;
}

int main()
{
	int len = 0;
	char str[10] = "Hello bit";
	len = mystrlen(str);
	printf("len = %d\n", len);
	return 0;
}