#include <stdio.h>
#include <windows.h>


void bubblesort(int a[], int len)//排序
{
	int i = len - 1;
	int j = 0;
	while( i )
	{
		int pos = 0;           //每趟循环开始前，还未交换
		for( j = 0; j < i; j++)
		{
			if( a[j] > a[j+1] )
			{
				a[j] ^= a[j+1];
				a[j+1] ^= a[j];
				a[j] ^= a[j+1];
				pos = j;                   //记录交换的位置
			}
		}
		i = pos;   //下趟只需比较到pos位置处就ok
	}
}

int main()
{
	int i = 0;
	int arr[] = {1,2,3,4,5,6,7,1,2,3,4,5,6};
	int len = sizeof(arr)/sizeof(arr[0]);
	for(i = 0; i<len; i++)
	{
		printf("%d  ",arr[i]);
	}
	printf("\n");
	bubblesort(arr, len);//排序
	printf("单独出现的数字为：");
	for(i = 0; i<len; i+=2)//每两个一比较,如果不相等则第一个为单独出现的
	{
		if(arr[i] != arr[i+1])
		{
			printf("%d  ", arr[i]);
			i -= 1;
		}
	}
	printf("\n");
	
	system("pause");
	return 0;
}