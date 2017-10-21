#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a = 0;
	int b = 0;
	int t = 0;
    printf("请输入两个数：");
	scanf("%d %d",&a,&b);
	if(a<b)
	{
		t = a;
		a = b;
		b = t;
	}
	while(a%b != 0)
	{
		t = a%b;
		a = b;
		b = t;
	}
	t = b;
	printf("最大公约数为：%d\n",t);
	system("pause");
	return 0;
}