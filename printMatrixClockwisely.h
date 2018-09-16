#include <stdio.h>

void PrintCircle(int **a, int columns, int rows, int start)
{
    int endX = columns - start - 1;
    int endY = rows - start - 1;

    //打印第一行
    int i = start;
    for(; i <= endX; ++i)
        printf("%d ", a[start][i]);
    
    //打印右列
    i = start + 1;
    for(; i <= endY; ++i)
        printf("%d ", a[i][endX]);

    //打印最后一行
    i = endX - 1;
    for(; i >= start; --i)
        printf("%d ", a[endY][i]);

    //打印左列
    i = endY - 1;
    for(; i >= start; --i)
        printf("%d ", a[i][start]);
}

void PrintMatrixClockwisely(int **a, int columns, int rows)
{
    if(a == NULL || columns <= 0 || rows <= 0)
        return ;

    int start = 0;
    while(start*2 < columns && start*2 < rows){
        PrintCircle(a, columns, rows, start);
        ++start;
    }

}

int TestMatrix()
{
    int a[5][5] = {
        {1,  2,  3,  4,  5},      
        {6,  7,  8,  9,  10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };


    printf("%d\n", a[0][0]);
    PrintMatrixClockwisely((int **)a, 5, 5);
    return 0;
}
