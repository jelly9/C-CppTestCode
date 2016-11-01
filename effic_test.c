#include <stdio.h>
#include <windows.h>

#define DEBUG1 1
#define DEBUG2 1
#define DEBUG3 0

int main()
{
	int start1 = 0, end1   = 0;
	int start2 = 0, end2   = 0;
	int start3 = 0, end3   = 0;
	int i = 0, j = 0;
	printf("Start test ...\n");

#if DEBUG1
	start1 = GetTickCount();//测试一
	for(i = 0; i<500; i++)
	{
		if( 0 == i%2 ) // 先判断再执行
		{
			for(j = 0; j<100; j++)         
			{
				printf("bit\n");         
			}
		}
		else
		{
			for(j = 0; j<100; j++)
			{
				printf("world\n");
			}
		}
	}
	end1 = GetTickCount();
#endif

#if DEBUG2
	start2 = GetTickCount();//测试二
	for(i = 0; i<500; i++)
	{
		for(j = 0; j<100; j++)          //先执行再判断
		{
			if( 0 == (i)%2 )       
			{
				printf("bit\n");
			}
			else
			{
				printf("world\n");
			}
		}
	}
	end2 = GetTickCount();
#endif

#if DEBUG3
	start3 = GetTickCount();//测试三
	for(i = 0; i<500; i++)
	{
		for(j = 0; j<100; j++)          
		{
			if( 0 == (i)%2 )       
			{
				printf("bit\n");
			}
			else
			{
				printf("world\n");
			}
		}
	}
	end3 = GetTickCount();
#endif	
	

#if DEBUG1           
	printf( "time1: %d\n", end1 - start1 );//测试一
#endif

#if DEBUG2          
	printf( "time2: %d\n", end2 - start2 );//测试二
#endif

#if DEBUG3          
	printf( "time3: %d\n", end3 - start3 );//测试三
#endif
	
	printf("End test ...\n");
	system("pause\n");
	return 0;
}