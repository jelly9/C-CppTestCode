//#include <stdio.h>
//#include <windows.h>
//#include <stdarg.h>
//
//int average( int n_values, ... )
//{
//	va_list var_arg;
//	int i;
//	int sum = 0;
//	va_start( var_arg, n_values );
//	for( i = 0; i<n_values; i += 1 )
//	{
//		sum += va_arg( var_arg, int );
//	}
//	va_end( var_arg );
//
//	return sum/n_values;
//}
//
//int mymax( int n_values, ...)
//{
//	va_list var_arg;
//	int i = 0;
//	int value = 0;
//	int ret = 0;
//	va_start( var_arg, n_values );
//	ret = va_arg(var_arg, int);
//	for( i = 0; i < n_values; i++)
//	{
//		value =  va_arg(var_arg, int );
//		if( ret < value )
//		{
//			ret = value;
//		}
//	}
//	va_end( var_arg );
//
//	return ret;
//}
//
//int main()
//{
//	printf("average = %d\n", average(3, 4,6,11) );
//	printf("max = %d\n", mymax(5, 6,2,3,4,10) );
//
//	system("pause");
//	return 0;
//}


#include <stdio.h>
#include <assert.h>
#include <stdarg.h>
#include <windows.h>

//递归输出int型数据
static int my_putint( int a )
{
    int prev = a / 10;
    if( 0 != prev )
    {
        my_putint(prev);
    }
    putchar( a%10 + '0');
}

int my_printf(const char *format,...)
{
	int _int;
	char _char;
	char *_string;
    va_list arg_list;
	const char *start = format;

    va_start(arg_list, format);
    while( *start != '\0')
    {
       if( *start == '%')
       {
           start++;
           switch(*start)
           {
		   case 'd'://整形
			   {
					_int = va_arg(arg_list,int);
					my_putint(_int);
					break;
			   }

		   case 's'://字符串型
			   {
				   _string = va_arg(arg_list, char *);
				   while( *_string )
				   {
					   putchar( *_string++ );
				   }
				   break;
			   }
		   case 'c'://字符型
			   {
				   _char = va_arg(arg_list, char);
				   putchar(_char);
				   break;
			   }

           }
       }
	   else
	   {
		   putchar(*start);
	   }
	   start++;
    }
	va_end(arg_list);

    return 0;
}


int main()
{
    int a = 10;
    const char *msg = "hello bit";
	char c = 'b';
    my_printf("number:%d\nstring:%s\nchar:%c\n", a, msg, c);
    
	system("pause");
	return 0;
}
