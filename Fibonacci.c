#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)

int fibc(int num)
{
	int i = 0;
	int ret = 0;
	int m = 1;
	int n = 0; 
	for(i = num; i>0; i--)
	{                     //i = 1  2  3  4  5  6  7   8   9  
		n = ret;//          n = 0  1  1  2  3  5  8   13  21
		ret = ret + m;//  ret = 1  1  2  3  5  8  13  21  34
		m = n;     //       m = 0  1  1  2  3  5  8   13  21
	}
	return ret;
}
//int fibc(int n)  
//{  
//    int arr[50]={0};//缺点：数组大小不灵活，通用性差  
//    int i=0;  
//    for(i=0; i<=n; i++)  
//    {  
//        if(i<=1)  
//            arr[i]=i;  
//        else  
//            arr[i]=arr[i-1]+arr[i-2];  
//    }  
//    return arr[n];  
//} 
int main()
{
	int num = 0;
	int ret = 0;
	printf("请输入一个数：");
	scanf("%d", &num);
	ret = fibc(num);
	printf("%d\n", ret);

	system("pause");
	return 0;
}

//
////int fibc(int n)//缺点：如果n较大，则效率大大降低  
////{  
//
////    if(n<=1)  
////        return n;  
////    else  
////        return fibc(n-1)+fibc(n-2);       
////}  
//
//
//
//int main()  
//{  
//    int num = 0;  
//    int ret = 0;  
//    printf("请输入一个整数:");  
//    scanf("%d",&num);  
//    ret = fibc(num);  
//    printf("第%d个斐波那契数为%d\n",num,ret);  
//    system("pause");  
//    return 0;  
//} 