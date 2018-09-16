#define _CRT_SECURE_NO_WARNINGS  1

#include <stdio.h>

int main()
{
	int i = 0;
	int j = 0;
	int n = 0;
	int arr[100][100] = {1};
	printf("Please input:");
	scanf("%d", &n);
	printf("\n");
	for( i = 1; i < n; i++)
	{
		for( j = 1; j <= i; j++)
		{
			arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
			printf("%-6d", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}