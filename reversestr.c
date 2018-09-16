#include <stdio.h>
#include <windows.h>
#include <assert.h>


char *reversestr( char *str )
{
	char *ret = str;
	char *start = str;
	char *end = str;
	while(*end)//让end指向结尾
	{
		end++;
	}
	end = end - 1;
	while(start<end)//实现交换
	{
		*start ^= *end;
		*end ^= *start;
		*start ^= *end;
		start++;
		end--;
	}
	return ret;
}
int main()
{
	char str[10] = "abcd";
	printf("%s\n", reversestr(str));

	system("pause");
	return 0;
};