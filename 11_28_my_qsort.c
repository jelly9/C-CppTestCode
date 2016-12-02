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

void swap(void *x, void *y, int width)
{
	int i = 0;
	char *_x = (char*)x;
	char *_y = (char*)y;
	for(i = 0; i < width; i++)
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
	int i = nums-1;
	int j = 0;
	int pos = 0;
	char *start = (char*)data;
	assert(data);

	while(i)
	{ 
		pos = 0;
		for(j = 0; j < i; j++)
		{
			if(cmp(start, start+width)>0)
			{
				start[j] ^= start[j+width];
				start[j+width] ^= start[j];
				start[j] ^= start[j+width];
				//swap(start,start+width,width);
				pos = j;
			}
		}
		i = pos;
	}
	
	//for(i = 0; i < nums-1; i++)
	//{
	//	flag = 0;
	//	//start = (char*)data;
	//	for(j = 0; j < nums-1-i; j++)
	//	{
	//		if( cmp(start, start+width) > 0 )
	//		{
	//			for(k = 0; k < width; k++)
	//			{
	//				/*start[k] ^= start[k+width];
	//				start[k+width] ^= start[k];
	//				start[k] ^= start[k+width];*/
	//				
	//			}
	//			flag = 1;
	//		}
	//		start += width;
	//	}
	//	if(!flag)
	//	{
	//		break;
	//	}
	//}

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