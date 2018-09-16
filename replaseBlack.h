#include <stdio.h>

void RepleaseBlack(char str[], int lenght)
{
    if(str == NULL || lenght <= 0)
        return;

    int originalLenght = 0;
    int numberOfBlack = 0;
    int i = 0;

    while(str[i] != '\0'){
        ++originalLenght;
        if(str[i] == ' ')
            ++numberOfBlack;

        ++i;
    }

    int newLenght = originalLenght + numberOfBlack*2;
    if(newLenght > lenght)
        return;

    int newIdx = newLenght;
    int originalIdx = originalLenght;
    while(originalIdx >= 0 && newIdx > originalIdx){
        if(str[originalIdx] == ' '){
            str[newIdx--] = '0';
            str[newIdx--] = '2';
            str[newIdx--] = '%';

        }else{
            str[newIdx--] = str[originalIdx];
        }
        --originalIdx;
    }
}

int TestRepleaseBlack()
{
    char str[1024] = "we are happy.";
    printf("befor: %s\n", str);
    RepleaseBlack(str, 18);
    printf("after: %s\n", str);
    return 0;
}
