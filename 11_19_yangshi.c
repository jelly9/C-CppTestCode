#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)

#define ROW 3
#define COL 3

int checknum( int (*p)[COL], int value )
{
	/*int i = 0;
	int j = 0;
	for( i = 0; i < ROW; i++ )
	{
		for( j = 0; j < COL; j++ )
		{
			if( value == a[i][j] )
			{
				return 1;
			}
		}
	}*/

	int i = 0;
	int j = COL-1;
	while( j+1 )
	{
		int *q = &(p[i][j]);
		if( *q == value )
		{
			return 1;
		}
		else if( *q < value )
		{
			p++;
		}
		else if( *q > value )
		{
			q--;
			j--;
		}
	}

	return 0;
}

int main()
{
	int i = 0;
	int j = 0;
	int ret = 0;
	int a[ROW][COL] = {1,2,3,4,5,6,7,8,9};
	

	for( i = 0; i < ROW; i++ )
	{
		for( j = 0; j < COL; j++ )
		{
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}

	ret = checknum( a, 5 );

	if(ret)
	{
		printf("找到了！\n");
	}
	else 
	{
		printf("没找到！\n");
	}


	system("pause");
	return 0;
}