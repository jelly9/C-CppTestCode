#include <stdio.h>
#include <string.h>


void test(){
    char buf1[] = "hello world";
    char buf2[1024] = {0};

    strcpy(buf2, buf1);

    printf("%s\n%s\n", buf1, buf2);
}

int main(){
    
    test();

    return 0;
}
