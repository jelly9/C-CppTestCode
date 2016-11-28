#include <stdio.h>
#include <windows.h>
#include <assert.h>

void show(int arr[], int len)
{
	int i = 0;
	for(i = 0; i < len; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");
}

int intCmp(void *x, void *y)
{
	int *_x = (int*)x;
	int *_y = (int*)y;
	return *_x - *_y;
}

void swap(void *x, void *y, int n)
{
	int i = 0;
	char *_x = (char*)x;
	char *_y = (char*)y;
	for(i = 0; i < n; i++)
	{
		*_x ^= *_y;
		*_y ^= *_x;
		*_x ^= *_y;
		_x++;
		_y++;
	}
}

void bubbleSort(void *data, int nums, int width, int (*cmp)(void*, void*))
{
	int i = 0;
	int j = 0;
	int flag = 0;
	char *start = (char*)data;
	int k = 0;
	assert(data);
	
	for(i = 0; i < nums-1; i++)
	{
		flag = 0;
		for(j = 0; j < nums-1-i; j++)
		{
			if( cmp(start, start+width) > 0 )
			{
				flag = 1;
				for(k = 0; k < width; k++)
				{
					start[k] ^= start[k+width];
					start[k+width] ^= start[k];
					start[k] ^= start[k+width];

				}
			}
			start += width;
		}
		if(!flag)
		{
			break;
		}
	}

}

int main()
{
	int arr[] = {21,432,43,54,3,234,2431,432,324,1221,9999,76};
	int len = sizeof(arr) / sizeof(arr[0]);

	show(arr, len);
	bubbleSort(arr, len, sizeof(int), intCmp);
	show(arr, len);

	system("pause");
	return 0;
}