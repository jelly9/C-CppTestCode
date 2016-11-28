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

void bubbleSort(void *data, int nums, int width, int (*cmp)(void*, void*))
{
	assert(data);

	int i = nums - 1;
	int j = 0;
	int pos = 0;
	char *start = (char*)data;
	while(i)
	{
		for(j = 0; j < i; j++)
		{
			if()
				swap(&arr[j], &arr[j+1]);
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