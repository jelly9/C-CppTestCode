//分治算法：
//	一年一度的欧冠开始了，其在初赛阶段采用循环制
//	设有n对参加，比赛初赛进行n-1天，每个队要和其
//	它队进行一场比赛，最后按照积分进入决赛，并且
//	不能轮空。请按照上述要求安排比赛对手，决定每
//	个队的对手


#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)

#define MAXN 64

int a[MAXN+1][MAXN+1] = {0};

void gamecal( int k, int n )
{
	int i, j;
	if( 2 == n )
	{
		a[k][1] = k;
		a[k][2] = k+1;
		a[k+1][1] = k+1;
		a[k+1][2] = k;
	}
	else 
	{
		gamecal( k, n/2 );
		gamecal( k+n/2, n/2 );
		for( i = k; i < k+n/2; i++ )
		{
			for( j = n/2+1; j <= n; j++ )
			{
				a[i][j] = a[i+n/2][j-n/2];
			}
		}
		for( i= k+n/2; i < k+n; i++ )
		{
			for( j = n/2+1; j <= n; j++ )
			{
				a[i][j] = a[i-n/2][j-n/2];
			}
		}
	}
}

int main()
{

	int m, i, j;
	printf("参赛球队数：");
	scanf("%d", &m);
	j = 2;
	for( i = 2; i < 8; i++ )
	{
		j *= 2;
		if( j == m )break;
	}
	if( i >8 )
	{
		printf("参赛球队数必须2的整数次幂，并且不能超过64。\n");
		system("pause");
		return 0;
	}
	gamecal( 1, m );
	printf("\n编号 ");
	for( i = 2; i <= m; i++ )
	{
		printf("%2d天 ", i-1);
	}
	printf("\n");
	for( i = 1; i <= m; i++ )
	{
		for( j = 1; j <= m; j++ )
		{
			printf("%4d ", a[i][j]);
		}
		printf("\n");
	}


	system("pause");
	return 0;
}
