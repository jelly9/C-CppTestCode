#include <stdio.h>
#include <windows.h>
#include <string.h>

int main()
{
	//int a[] = {1,2,3,4};
	char a[] ="abcde";          //int           char
	printf("%d\n", sizeof(a) );//16            6
	printf("%d\n", sizeof(a+0) );//4           4
	printf("%d\n", sizeof(*a) );//4             1
	printf("%d\n", sizeof(a+1) );//4            4
	printf("%d\n", sizeof(a[1]) );//4           1
	printf("%d\n", sizeof(&a) );//4            4
	printf("%d\n", sizeof(&a+1) );//4          ?   4
	printf("%d\n", sizeof(&a[0]) );//4         4
	printf("%d\n", sizeof(&a[0]+1) );//4       ?   4
	printf("%d\n\n", sizeof(*&a) );//16          ?  6

	/*printf("%d\n", strlen(a) );
	printf("%d\n", strlen(a+1) );
	printf("%d\n", strlen(*a) );
	printf("%d\n", strlen(a[1]) );
	printf("%d\n", strlen(&a) );
	printf("%d\n", strlen(&a+1) );
	printf("%d\n", strlen(&a[0]+1) );*/

	system("pause");
	return 0;
}