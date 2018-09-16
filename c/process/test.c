/**
  * @file 
  *  * @author xiaoguodong 1799553128@qq.com
  *   * @date 
  *    * @brief
  *     **/

#include <stdio.h>
#include <stdlib.h>

int g_val = 10;

void func(){
    int f_a = 10;
    int f_b = 20;
    printf("   f_a: %p\n", &f_a);
    printf("   f_b: %p\n", &f_b);
}

int main(){
    int st_a = 30;
    int st_b = 40;
    static int s_val = 30;
    int *hp_pa = (int*)malloc(sizeof(int));
    int *hp_pb = (int*)malloc(sizeof(int));


    printf("  st_a: %p\n", &st_a);
    printf("  st_b: %p\n", &st_b);
    printf("&hp_pa: %p\n", &hp_pa);
    printf("&hp_pb: %p\n", &hp_pb);
    func();
    printf(" hp_pa: %p\n", hp_pa);
    printf(" hp_pb: %p\n", hp_pb);
    printf(" g_val: %p\n", &g_val);
    printf(" s_val: %p\n", &s_val);
    printf("  main: %p\n", main);
    printf("  func: %p\n", func);

    return 0;
}
