#include "effic.h"

uint reverse_bit1(uint x)                                                                    
{  
    uint i, ret=0;  
    for (i = 0; i < 32; i++)  
    {  
        ret += ((x >> i) & 1)*(uint)pow(2, 31 - i); //实际上没有翻转，只是从最低位向最高位扩展求得  
    }
    return ret;  
}  

int reverse_bit2(int num)
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
	return ret;
}