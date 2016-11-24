#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define N 5

void swap(int *x, int *y)//交换
{
	*x ^= *y;
	*y ^= *x;
	*x ^= *y;
}

void show(int arr[], int n)//打印数组
{
	int i = 0;
	for( i = 0; i < n; i++ )
	{
		printf("%d  ", arr[i] );
	}
	printf("\n");
}

void setarr(int arr[], int n)//给数组赋值
{
	int i = 0;
	srand((unsigned)time(NULL));
	for( i = 0; i < N; i++)
	{
		arr[i] = rand()%100+1;
	}
}

//找最小值与第一个交换，找次小值与第二个交换，以此类推。。。
void select_sort(int arr[], int len)
{
	int i = 0;
	int j = 0;
	int pos = 0;
	
	for(i = 0; i < len-1; i++)
	{
		pos = i;
		for(j = i+1; j < len; j++)//在无序组中找最小值
		{
			if(arr[pos] > arr[j])
			{
				pos = j;
			}
		}
		if(pos != i) ·																																																																						
		{
			swap(&arr[i], &arr[pos]);
		}
	}
}

int main()
{
	int a[N] = {5,4,3,2,1};
	//setarr(a, N);

	show(a, N);
	select_sort(a, N);
	show(a,N);



	system("pause");
	return 0;
}