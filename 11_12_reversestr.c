#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)




//void reverse_str(char *start, char *end)
//{
//
//	if( start < end )
//	{
//		*start ^= *end;
//		*end ^= *start;
//		*start ^= *end;
//		printf("hh\n");
//		reverse_str( ++start, --end );
//	}
//	
//}

void reverse_str(char *str, int len)
{
	int e = len - 1;
	if( &str[0] <= &str[e] )//递归出口条件
	{
		str[0] ^= str[e];
		str[e] ^= str[0];
		str[0] ^= str[e];
		len -= 2;
		reverse_str( &str[1], len);
	}
}

//void reverse_str( char *str )
//{
//	if( *str != '\0')
//	{
//		reverse_str(str+1);
//	}
//	putchar(*str);
//}

int main()
{
	/*char arr[] = "abcd";
	reverse_str(arr);*/
	char arr[] = "abcd1234";
	int len = sizeof(arr) / sizeof(arr[0]) - 1;

	printf("before: %s\n",  arr);
	reverse_str(arr, len);
	printf("after : %s\n",  arr);

	system("pause");
	return 0;
}