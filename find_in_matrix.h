#include <stdio.h>

int Find(int *matrix, int rows, int columns, int val)
{
    if(matrix != NULL && rows > 0 && columns > 0){
        int row = 0;
        int col = columns - 1;
        while(row < rows && col >=0 ){
            if(matrix[row*columns+col] == val)
                return 1;
            else if(matrix[row*columns+col]  > val)
                --col;
            else
                ++row;
        }
    }
    return 0;
}

int Find()
{
    int a[4][4] = {
        {1, 2, 8, 9},
        {2, 4, 9, 12},
        {4, 7, 10, 13},
        {6, 8, 11, 15}
    };

    int ret = Find((int*)a, 4, 4, 100);
    printf("%d\n", ret);

    return 0;
}
