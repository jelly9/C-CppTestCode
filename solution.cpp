#include <iostream>
#include <vector>


class Solution {
public:
    void FindNumsAppearOnce(std::vector<int> data,int* num1,int *num2) {
        if(data.size() < 2){
            return;

        }

        int temp = 0;
        *num1 = *num2 = 0;
        //计算两个只出现一次数字异或的结果
        for(size_t i = 0; i < data.size(); ++i){
            temp = temp ^ data[i];
        }
        //计算两个只出现一次数字的第一个不相同的bit位
        int n = first_bit_one(temp);
        int m = 1<<n;
        for(size_t i = 0; i < data.size(); ++i){
            if((data[i] & m )== 0){
                *num1 = *num1 ^ data[i];
            }
            else{
                *num2 = *num2 ^ data[i];
            }
        }
    }

private:
    int first_bit_one(int num){
        int res = 0;
        while(((num & 1) != 1) && (8*sizeof(32))){
            num = num >> 1;
            ++res;
        }
        return res;
    } 
};
