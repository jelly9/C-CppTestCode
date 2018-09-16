#include <iostream>
#include<string>
#include <string.h>
using namespace std;

string st1,st2;

void solution(){
    char ch[80];
    int len=st1.length();    //st1字符串比st2肯定要长
    int j=0,count=0;
    bool flag = 0;

    for(int i=0;i<len;i++){
        if(st1[i]==st2[j]){
            j++;                 //两个字符串相等则比较两者的下一个
        }
        else{
            ch[count++]=st1[i];  //字符串不相等，则将st1中的字符串放入字符数组中
        }
    }

    for(int i=0;i<count;i++){
        if(islower(ch[i])){
            ch[i]=toupper(ch[i]); //将小写字符转化成大写
        }
        for(int k=0;k<i;k++){
            if(ch[k]==ch[i])     //去掉重复的字符
                flag=1;
        }

        if(!flag){
            cout<<ch[i];
        }
        flag=0;
    }
}

int main()
{
    cin>>st1>>st2;
    solution();

    return 0;
}
