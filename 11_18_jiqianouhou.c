#include <stdio.h>
#include <windows.h>

void show( int a[], int len )
{
	int i = 0;
	for( i = 0; i < len; i++ )
	{
		printf("%4d", a[i]);
	}
	printf("\n");
}
void swap( int *xp, int *yp )
{
	*xp ^= *yp;
	*yp ^= *xp;
	*xp ^= *yp;
}

void joswitch( int a[], int len )
{
	int i = 0;
	int j = len - 1;;
	while ( i < j )
	{
		while( ((a[i] & 1) == 1) && i<j )
		{
			i++;
		}
		while( ((a[j] & 1) == 0) && i<j )
		{
			j--;
		}
		if(i<j)
		{
			swap(&a[i], &a[j]);
			i++;
			j--;
		}
	}

}


int main()
{

	int arr[9] = {1,3,9,3,5,6,7,8,9};
	int len = sizeof(arr) / sizeof(arr[0]);

	show(arr, len);
	joswitch(arr, len);
	show(arr, len);

	system("pause");
	return 0;
}
