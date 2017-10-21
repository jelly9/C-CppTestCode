#include <stdio.h>

int main()
{
	int arr[9] = {1,2,3,4,5,1,2,3,4};
	int i = 0;
	int a = arr[0]; 
	for( i = 1; i < 9; i++)
	{
		a ^= arr[i];
	}
	printf("The single number is:%d\n",a);
	return 0;
}