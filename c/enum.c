/**
 * @file 
 *  * @author xiaoguodong jellyxio@qq.com
 *   * @date 
 *    * @brief
 *     **/

#include <stdio.h>

enum A{
    ONE = 0,
    TWO,
    THREE
};

enum B{
    FIRST = 0,
    SECOND,
    THIRD
};

int main()
{
    enum A a1 = ONE;
    int i1 = a1;

    int i2 = 0;
    enum A a = i2;

    return 0;
}
