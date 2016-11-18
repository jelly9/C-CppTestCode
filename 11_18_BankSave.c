
//Sun使用整存零取的方式在银行存了四年的生活费，
//他每个月月末取下个月的生活费，先假设月利息是
//1.71%，请编写函数实现他许村多少钱。

#include <stdio.h>
#include <windows.h>

#define RATE  0.0171
#define FETCH 1000

int main()
{
	double corpus[49];
	int i = 0;;
	corpus[48] = (double)FETCH;
	for( i = 47; i > 0; i-- )
	{
		corpus[i] = ( corpus[i+1] + FETCH ) / ( 1 + RATE/12 );
	}
	for( i = 48; i > 0; i-- )
	{
		printf("%d月月末本息共计：%.2f\n", i, corpus[i]);
	}
	system("pause");
	return 0;
}