#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)

int main()
{

	int money = 0; 
	scanf("%d",&money);
	printf("%d\n",2*money - 1);

	system("pause");
	return 0;
}
//分析
//首先喝完用空瓶换，完了再用空瓶换到最最后不能换的时候，手中肯定只剩一个一个空瓶
//假如有N块钱，则喝完有N个空瓶，问老板借N-1个空瓶，则可再换N-1瓶汽水，
//完了之后把喝完的N-1个空瓶还给老板，则刚好喝了2N-1瓶汽水,而且手中余一个空瓶

//
//int count_bottle_num(int money)
//{
//	int num = 0;
//	int null_bottle = 0;
//	int full_bottle = money;
//	while (1)
//	{
//		num += full_bottle;
//		null_bottle = full_bottle+null_bottle%2;
//		full_bottle = null_bottle / 2;
//		if (null_bottle == 1)
//		{
//			return num+1;
//			
//		}
//	}
//	
//}
//int main()
//{
//	int money = 0;
//	printf("请输入金额：");
//	scanf("%d",&money);
//	printf("%d元钱可以喝%d瓶汽水！！\n",money,count_bottle_num(money));
//
//
//	system("pause");
//	return 0;
//}