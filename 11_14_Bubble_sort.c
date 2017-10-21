#include <stdio.h>
#include <windows.h>

void show( int arr[], int len )
{
	int i = 0;
	for( ; i < len; i++ )
	{
		printf("%4d", arr[i]);
	}
	printf("\n");
}

//常规冒泡排序法
void bubble_sort2( int arr[], int len )
{
	int i = 0;
	int j = 0;
	for( i = len-1; i > 0; i-- )
	{
		for( j = 0; j < i; j++ )
		{
			if( arr[j] >arr[j+1] )
			{
				arr[j] ^= arr[j+1];
				arr[j+1] ^= arr[j];
				arr[j] ^= arr[j+1];
			}
		}
	}
}

	
//改进的冒泡排序法
void bubble_sort1( int arr[], int len )
{
	int pos = 0;//设置标记，记录每次交换位置
	int i = len - 1;
	int j = 0;
	while(i)
	{
		for( j = 0; j < i; j++ )//1 2 3 4 5 6 7 8 
		{
			if( arr[j] > arr[j+1] )
			{
				arr[j] ^= arr[j+1];
				arr[j+1] ^= arr[j];
				arr[j] ^= arr[j+1];
			}
			pos = j;
		}
		i = pos;
	}
}

int main()
{
	int arr[] = {3,1,5,7,8,6,4,2};
	int len = sizeof(arr) / sizeof(arr[0]);
	

	show( arr, len );
	bubble_sort1( arr, len );
	show( arr, len );

	system("pause");
	return 0;
}