#include <stdio.h>
#include <windows.h>
#include <assert.h>

char *mystrstr( const char *str1,const char *str2)
{
	//   思路:
	//   str1   abcabcdef   
	//   str2   abcd        |
	//           abcd       |
	//            abcd      V
	//             abcd        找到了，返回


	const char *p = str1;
	const char *q = str2;
	const char *s = NULL;
	assert(str1);
	assert(str2);
	if('\0' == *q)//子字符串为空则返回母字符串
	{
		return (char*)p;
	}
	while(*p)
	{
		s = p;
		while( *p && *q && *p == *q )//挨个比较         // abcabcdef -> abcabcdef  -> abcabcdef -> abcabcdef
		{//                                              abcd      ->  abcd      ->   abcd    ->    abcd    ->  找到了，返回
			p++;
			q++;
		}
		if('\0' == *q)//子字符串指向‘\0’则说明母字符串包含子字符串
		{
			return (char *)s;
		}
		p = s+1;//否则从母字符串下一个元素比较
		q = str2;
	}
	return NULL;//直至str1指向空时还未找到则返回空
}


int main()
{
	char str1[100] = "abcabcdefg";
	char str2[100] = "abcd";
	printf("%s\n", mystrstr(str1, str2));

	system("pause");
	return 0;
}






