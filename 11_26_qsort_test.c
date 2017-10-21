#include <stdio.h>
#include <search.h>
#include <windows.h>

void show(int a[], int n)
{
	int i = 0;
	for(i = 0; i < n; i++)
	{
		printf("%4d", a[i]);
	}
	printf("\n");
}

int compare(int x, int y)
{
	return *(int*)x - *(int*)y; 
}


int main()
{
	int i = 0;
	int   i_arr[10] = {1, 3, 5, 7, -1, -2, 8, 6, 4, 2};
	float f_arr[10] = {1.2, 1.4, 2.6, 3.4, 10.3, 0.8, -3.2, 9.5, 23.4, 99.9};
	char  str[10]   = {'a', 'c', 'e', 'f', 'h', 'i', 'g', 'd', 'b', 'z'};
	show(i_arr, 10);
	qsort( (void *)i_arr, (size_t)10, sizeof( char * ), (int)compare );
	show(i_arr, 10);




	system("pause");
	return 0;
}