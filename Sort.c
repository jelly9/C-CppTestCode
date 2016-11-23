#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define N 10

void show(int arr[], int n)
{
	int i = 0;
	for( i = 0; i < n; i++ )
	{
		printf("%d  ", arr[i] );
	}
	printf("\n");
}

void setarr(int arr[], int n)
{
	int i = 0;
	srand((unsigned)time(NULL));
	for( i = 0; i < N; i++)
	{
		arr[i] = rand()%100+1;
	}
}

int main()
{
	int a[N];
	setarr(a, N);
	show(a, N);


	system("pause");
	return 0;
}