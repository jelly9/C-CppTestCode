#include <stdio.h>
#include <windows.h>
#include <assert.h>
#include <string.h>

char *my_strcpy( char *dst, const char *scr )
{
	char *ret = dst;//保存返回地址

	assert(dst);
	assert(scr);

	while( *dst++ = *scr++ );//实现拷贝

	return ret;
}

char *my_strncpy( char *dst, const char *scr, unsigned int n )
{
	char *ret = dst;
	int i = n - 1;

	assert(dst);
	assert(scr);
	assert( n <= strlen(scr) );
	assert( n <= strlen(dst) );

	//while( i > 0 )//逆序拷贝
	//{
	//	dst++;
	//	scr++;
	//	i--;
	//}

	while( ( n-- > 0 ) && ( *dst++ = *scr++ ) );//逆序拷贝n个
	
	return ret;
}

char *my_strcat( char *dst, const char *scr )
{
	char *ret = dst;

	assert(dst);
	assert(scr);

	while( '\0' != *dst )
		dst++;//找到dst结尾

	while( *dst++ = *scr++ );//实现链接

	return ret;
}

char *my_strncat( char *dst, const char *scr, int n )
{
    char *ret=dst;

    while(*dst)//找到dst结尾
        dst++;

    while( ( n-- > 0 ) && ( *dst++ = *scr++ ) );//拷贝n个
	*dst = '\0';

    return ret;
}

int my_strcmp( const char *dst, const char *scr )
{
	assert(dst);
	assert(scr);
	while( '\0' != *dst && '\0' != *scr )
	{
		if( *dst == *scr )
		{
			dst++;
			scr++;
		}
		else if(*dst > *scr)
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}
	if( *dst != '\0' && *scr == '\0')
	{
		return 1;
	}
	if( *dst == '\0' && *scr != '\0')
	{
		return -1;
	}

	return 0;
}

int my_strncmp( const char *dst, const char *scr, int n )
{
	assert(dst);
	assert(scr);
	while( n>0 && '\0' != *dst && '\0' != *scr )
	{
		if( *dst == *scr )
		{
			dst++;
			scr++;
		}
		else if(*dst > *scr)
		{
			return 1;
		}
		else
		{
			return -1;
		}
		n--;
	}
	if( *dst != '\0' && *scr == '\0')
	{
		return 1;
	}
	if( *dst == '\0' && *scr != '\0')
	{
		return -1;
	}

	return 0;
}

void *my_memcpy( void *dst, const void *scr, int n )
{
	void *ret = dst;
	assert(dst);
	assert(scr);
	if( NULL == dst || NULL == scr )
	{
		return dst;
	}
	while(n--)
	{
		*(char*)dst = *(char*)scr;
		dst = (char*)dst + 1;
		scr = (char*)scr + 1;
	}
	return ret;
}

void *my_memmove( void *dst, const void *src, int n )
{
	char *_dst = (char*)dst;
	char *_src = (char*)src;
	char *ret =_dst;

	assert(dst);
	assert(src);

	if( _src >= _dst || _src+n <= _dst )//从前往后拷贝
	{
		while(n--)
		{
			*_dst = *_src;
			_dst++;
			_src++;
		}
	}
	else
	{
		char *_dst_end = _dst + n - 1;
		char *_src_end = _src + n - 1;
		while (n--)
		{
			*_dst_end = *_src_end;
			_dst_end--, _src_end--;
		}
	}
	return ret;
}

char *mystrstr( const char *str1,const char *str2)
{
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
		while( *p && *q && *p == *q )
		{//                                             
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
	char src[32]="abcdefgh";
	my_memmove(src, src+1, strlen(src) + 1);
	printf("%s\n",src);

	system("pause");
	return 0;
}
