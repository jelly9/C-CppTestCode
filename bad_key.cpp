
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

char s1[80] = {0}; //应该输入的文字
char s2[80] = {0}; //实际输入的文字

void solution(){
    bool input[128]; //实际输入
    string bad_key; //坏键

    for(int i = 0; i < 128; ++i){
        input[i] = false;

    }

    //统计实际输入
    for(int i = 0; s2[i] != '\0'; ++i){
        input[s2[i]] = true;
    }

    //统计坏键
    for(int i = 0; s1[i] != '\0'; ++i){
        if(input[s1[i]] == false){ 
            if(s1[i] >= 'a' && s1[i] <= 'z'){
                bad_key.push_back(s1[i] + 32);
            }else{
                bad_key.push_back(s1[i]);
            }
        }
    }

    cout << bad_key.c_str() << endl;
}

int main(){
    cin >> s1 >> s2;
    solution();
    return 0;
}
