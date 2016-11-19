
//汉诺塔问题
//	寺院里有三根柱子，第一根上有64个盘子，从上往下
//	盘子越来越大，方丈要求小和尚A1把这些盘子全部移
//	动到第三根柱子上去。在移动的时候只能小盘子压着
//	大盘子，而且每次只能移动一个。

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