#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <windows.h>
#include <assert.h>

char *my_strncat(char *dest,char *stc,int len)
{
    char *cp=dest;
    while(*cp)
        cp++;
    while((*stc!='\0')&&(len--))
        *cp++=*stc++;
    *cp='\0';
    return dest;
}


int main()
{
	char str1[100] = {0};
	char str2[100] = {0};
	printf("ÇëÊäÈëÁ½¸ö×Ö·û´®£º\n");
	gets(str1);
	gets(str2);
	if( strlen(str1) == strlen(str2) )
	{ 
		
		if( strstr( strcat(str1,str1), str2 ) != NULL )
		{
			printf("is revolved!\n");
		}
		else
		{
			printf("is not revolved!\n");
		}
	}
	else
	{
		printf("is not revolved!\n");
	}


	system("pause");
	return 0;
}