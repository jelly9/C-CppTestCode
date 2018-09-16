#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

#define ATOI_ERR 0xffffffff


int myatoi(char *str){
    assert(str);
    long i = 0;
    int flag = 1;

    while(isspace(*str))
        ++str;

    if(*str != '\0' && *str == '-'){
        flag = -1;
        ++str;
    }else if(*str != '\0' && *str == '+'){
        ++str;
    }

    while(*str != '\0' && *str >= '0' && *str <= '9'){
        i *= 10;
        i += (*str - '0');
        ++str;
        if(i > __INT32_MAX__)
            return ATOI_ERR;
    }

    return flag*i;
}

void test(){
    char *str0 = "198798711223456789123456";
    char *str1 = "198798709813456789123456";
    char *str2 = "12.3abc45";
    char *str3 = "abc12345";
    char *str4 = "  12345abc";
    char *str5 = "- 123 456";

    printf("%d  %d\n", atoi(str0), myatoi(str0)); //12345  
    printf("%d  %d\n", atoi(str1), myatoi(str1)); //12345  
    printf("%d  %d\n", atoi(str2), myatoi(str2)); //123    
    printf("%d  %d\n", atoi(str3), myatoi(str3)); //0      
    printf("%d  %d\n", atoi(str4), myatoi(str4)); //12345  
    printf("%d  %d\n", atoi(str5), myatoi(str5)); //0      

    printf("%d \n", __INT32_MAX__);
}
int main(){

    test();
    return 0;
}
