#include <stdio.h>
#include <windows.h>

char *spaceswap( char *str )
{
	char *ret = str;
	char *rear = str;
	while( *rear != '\0') //使指向字符串结尾
	{
		rear++; 
	}

	while( *str != '\0')
	{
		if( *str == ' ')//判断是否为空格
		{
			char *p = rear+2;//Are you ok?'\0'
			char *q = rear+2;
			while( str < rear )//元素依次后移两位
			{
				*p = *rear;
				rear--;
				p--;
			}
			*str = '%';
			*(str+1) = '2';
			*(str+2) = '0';
			rear = q;//更新rear使指向尾部
		}
		str++;
	}
	return ret;
}

int main()
{
	char str[100] = " We are happy! ";
	printf("Before swap; %s\n", str);
	printf("After swap: %s\n", spaceswap(str));

	system("pause");
	return 0;
}