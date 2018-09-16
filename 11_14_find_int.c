#include <stdio.h>
#include <windows.h>

int *find_int( int key, int arr[], int len)
{
	int i = 0;
	for( i = 0; i < len; i++)
	{
		if( arr[i] == key)
			return &arr[i];
	}
	return NULL;
}


int main()
{

	int a[10] = {1,4,7,8,3,5,23,6,90,100};
	int k = 5;
	int l = sizeof(a)/sizeof(a[0]);
	int *p = find_int( k, a, l);
	printf("address:%p\npos:%d\n", p, (p-a)+1 );

	system("pause");
	return 0;
}