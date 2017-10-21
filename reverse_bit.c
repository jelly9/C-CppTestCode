#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>  
#include<math.h>  

#define DEBUG1 0             //条件编译
#define DEBUG2 1

typedef unsigned int uint;

#if DEBUG1
uint reverse_bit(uint x)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
{  
    uint i, ret=0;  
    for (i = 0; i < 32; i++)  
    {  
        ret += ((x >> i) & 1)*(uint)pow(2, 31 - i); //实际上没有翻转，只是从最低位向最高位扩展求得  
    }
	printf("DEBUG1\n");
    return ret;  
}  
#endif

#if DEBUG2
int reverse_bit(int num)
{
	int ret = 0;
	int count = 0;
	while(num)
	{
		count++;                      //00000000 00000000 00000000 00000001
		ret = ret + num%2;
		ret <<= 1;
		num >>= 1;
	}
	ret <<= (31-count);
	printf("DEBUG2\n");
	return ret;
}
#endif

int main()  
{  
    uint num = 0;
	uint ret = 0;  
    printf("Please input a number:");
    scanf("%u", &num);  
    ret = reverse_bit(num);  
    printf("翻转后的值为:%u\n", ret);

    return 0;  
} 