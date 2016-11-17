#include <stdio.h>
#include <windows.h>

#pragma  warning(disable:4996)

void move(int n, int x, int y, int z)
{
	if( 1 == n )
	{
		printf("%c-->%c\n",x, z);
	}
	else 
	{
		move (n-1, x, z, y);
		printf("%c-->%c\n\n", x, z);
		move(n-1, y, x, z);
	}
}

int main()
{
	int h;
	printf("输入盘子个数：");
	scanf("%d", &h);
	printf("移动%2d个盘子的顺序如下：\n", h);
	move(h, 'a', 'b', 'c');
	system("pause");
	return 0;
}