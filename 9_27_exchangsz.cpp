#include<stdio.h>

int main()
{
	int A[] = {1,2,3,4,5};
	int B[] = {6,7,8,9,0};
    int i = 0;
	int j = 0;
	printf("交换前：\n");
	printf("数组A：");
    for(i = 0; i<sizeof(A)/sizeof(A[0]); i++)
	{
		printf("%d ",A[i]);
	}
	printf("\n数组B：");
	for(i = 0; i<sizeof(B)/sizeof(B[0]); i++)
	{
		printf("%d ",B[i]);
	}
	for(i = 0; i<sizeof(A)/sizeof(A[0]); i++)
	{
		int temp = 0;
		temp = A[i];
		A[i] = B[i];
		B[i] = temp;
    }
	printf("\n交换后:\n");
	printf("数组A：");
    for(i = 0; i<sizeof(A)/sizeof(A[0]); i++)
	{
		printf("%d ",A[i]);
	}
	printf("\n数组B：");
	for(i = 0; i<sizeof(B)/sizeof(B[0]); i++)
	{
		printf("%d ",B[i]);
	}
    printf("\n"); 
	return 0;
}