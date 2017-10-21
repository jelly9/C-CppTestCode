#include <stdio.h>


//1、未改进。

//void BubbleSort(int a[], int len)
//{
//	int i = 0;
//	int j = 0;
//	for( i = 0; i < len-1; i++)
//	{
//		for( j = 0; j < len-i-1; j++ )
//		{
//			if(a[j]>a[j+1])
//			{
//				*(a+j)   = *(a+j) ^ *(a+j+1);
//				*(a+j+1) = *(a+j) ^ *(a+j+1);
//				*(a+j)   = *(a+j) ^ *(a+j+1);
//			}
//		}
//	}
//}



//2、改进后（设置变量pos记录最后交换的位置）。

//void BubbleSort(int a[], int len)
//{
//	int i = len - 1;
//	int j = 0;
//	while( i )
//	{
//		int pos = 0;           //每趟循环开始前，还未交换
//		for( j = 0; j < i; j++)
//		{
//			if( a[j] > a[j+1] )
//			{
//				*(a+j)   = *(a+j) ^ *(a+j+1);
//				*(a+j+1) = *(a+j) ^ *(a+j+1);
//				*(a+j)   = *(a+j) ^ *(a+j+1);
//				pos = j;                   //记录交换的位置
//			}
//		}
//		i = pos;   //下趟只需比较到pos位置处就ok
//	}
//
//}
//3、再改进后（每趟比较两次，分别找出一个最大值和一个最小值）。

void BubbleSort(int a[], int len)
{
	int j = 0;
	int low = 0;
	int high = len - 1;
	while(low<high)
	{
		for( j = low; j<high; j++)
		{
			if(a[j]>a[j+1])
			{
				*(a+j)   = *(a+j) ^ *(a+j+1);
				*(a+j+1) = *(a+j) ^ *(a+j+1);
				*(a+j)   = *(a+j) ^ *(a+j+1);
			}
		}
		high--;
		for( j = high; j>low; j--)
		{
			if(a[j]>a[j+1])
			{
				*(a+j)   = *(a+j) ^ *(a+j+1);
				*(a+j+1) = *(a+j) ^ *(a+j+1);
				*(a+j)   = *(a+j) ^ *(a+j+1);
			}
		}
		low++;
	}
}

//void BubbleSort(int a[])
//{
//	int len = sizeof(a)/sizeof(a[0]);
//	for( int i = 0; i < len-1; i++)
//	{
//		for( int j = 0; j < len-i-1; j++ )
//		{
//			if(a[j]>a[j+1])
//			{
//				//int t    = *(a+j);
//                //*(a+j)   = *(a+j+1);
//                //*(a+j+1) = t;
//				*(a+j)   = *(a+j) ^ *(a+j+1);
//				*(a+j+1) = *(a+j) ^ *(a+j+1);
//				*(a+j)   = *(a+j) ^ *(a+j+1);
//			}
//		}
//	}
//}

//主函数

int main()
{
    void BubbleSort(int *a, int l);        //void BubbleSort(int *a);
	int arr[] = {398,37,687,65,456,998,876,156,587,294};
	int i = 0;
	int j = 0;
	int len = sizeof(arr)/sizeof(arr[0]);
	printf("排序前: ");
    for( i = 0; i < len; i++ )
	{
		printf("%d  ", *(arr+i));
	}
    BubbleSort(arr,len);                 //BubbleSort(arr);
    printf("\n排序后: ");
    for( i = 0; i < len; i++ )
	{
		printf("%d  ", *(arr+i));
	}
	printf("\n");
	return 0;
}