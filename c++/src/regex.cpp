#include <iostream>
#include <string>

typedef enum {
    NORMAL_CH,
    RAND_CH,
    RAND_NUM,
    SUCCESS,
    FALLED

}STAT;

bool match(char* str, char* pattern)
{
    STAT stat = NORMAL_CH;
    char *ps = str;
    char *pp = pattern;
    while(ps != NULL){
        switch(stat){
        case NORMAL_CH://正常字符匹配模式
            if(*pp == '.'){
                stat = RAND_CH;
            }else if (*pp == '*'){
                stat = RAND_NUM;
            }else if (1){

            }
            break;
        case RAND_CH: //'.'

            break;
        case RAND_NUM://'*'

            break;
        default:

            break;
        }
    }
    return true;
}

int main()
{

    return 0;
}
