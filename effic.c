#include "effic.h"

void test()
{
	int start1 = 0, end1   = 0;
	int start2 = 0, end2   = 0;
	int start3 = 0, end3   = 0;
	int start4 = 0, end4   = 0;
	int i = 0, j = 0;

	printf("Start test...\n\n");

	#if DEBUG1//测试一
		start1 = GetTickCount();
		for(i = 0; i<CONDITION1; i++)
		{
			reverse_bit1( i );
		}
		end1 = GetTickCount();
	#endif

	#if DEBUG2//测试二
		start2 = GetTickCount();
		for(i = 0; i<CONDITION1; i++)
		{
			reverse_bit2( i );
		}
		end2 = GetTickCount();
	#endif

	#if DEBUG3//测试三
		start3 = GetTickCount();
		for(i = 0; i<CONDITION1; i++)
		{
			printf("aaaa\n");
		}
		end3 = GetTickCount();
	#endif	

	#if DEBUG4//测试四
		start4 = GetTickCount();
		for(i = 0; i<CONDITION1; i++)
		{
			printf("zzzz\n");
		}
		end4 = GetTickCount();
	#endif
	
	#if DEBUG1
		printf( "Time of test1: %d\n", end1 - start1 );
	#endif
	#if DEBUG2
		printf( "Time of test2: %d\n", end2 - start2 );
	#endif
	#if DEBUG3
		printf( "Time of test3: %d\n", end3 - start3 );
	#endif
	#if DEBUG4
		printf( "Time of test4: %d\n", end4 - start4 );
	#endif

	printf("\nEnd test...\n");
}

void meun()  //打印菜单
{
	printf("     Welcome to test      \n");
	printf("---------------------------\n");
	printf("-----  1.Start test.   ----\n");
	printf("-----  0.Exit test.    ----\n");
	printf("---------------------------\n");
}

uint reverse_bit1(uint x)                                                                    
{  
    uint i, ret=0;  
    for (i = 0; i < 32; i++)  
    {  
        ret += ((x >> i) & 1)*(uint)pow(2, 31 - i); //实际上没有翻转，只是从最低位向最高位扩展求得  
    }
    return ret;  
}  

int reverse_bit2(int num)             //00000000 00000000 00000000 00000001
{
	int ret = 0;
	int count = 0;
	while(num)
	{
		count++;                      
		ret += num%2;                //                                   1
		ret <<= 1;                       //                              10
		num >>= 1;                    //00000000 00000000 00000000 00000000
	}
	ret <<= (31-count);               //10000000 00000000 00000000 00000000 
	return ret;
}

