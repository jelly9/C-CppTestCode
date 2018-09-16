#define _CRT_SECURE_NO_WARNINGS  1

#include <stdio.h>

void bin_search( int *arr, int left, int right, int key )
{
	while( left <= right )
	{
		int mid = ( left & right)+( ( left^right )>>1 );
		if( key < arr[mid] )
		{
			right = mid - 1;
		}
		else
		{
			if( key > arr[mid])
			{
				left = mid + 1;
			}
			else
			{
				printf("找到了: arr[%d] = %d\n", mid - 1, arr[mid]);
				break;
			}
		}
	}
	if( left > right)
	{
		printf("没找到！\n");
	}
}
int main()
{
	int ret = 0;
	int key = 0;
	int arr[] = {0,1,2,3,4,5,6,7,8,9};
	int left = 0;
	int right = sizeof(arr)/sizeof(arr[0])-1;
	printf("请输入要查找的数字：");
	scanf("%d", &key);
	bin_search( arr, left, right, key );
	return 0;
}