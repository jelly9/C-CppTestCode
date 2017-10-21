#include <stdio.h>
#include <string.h>

int main()
{
	
	int i = 0;
	char password[10] = {0};

	for(i = 0; i < 3; i++)
	{
		printf("ÇëÊäÈëÃÜÂë£º");
		scanf("%s", password);
		if( strcmp(password,"666666") == 0 )
		{
			printf("µÇÂ½³É¹¦!!!\n");
			break;
		}
		else
		{
			if( i != 2)
			printf("ÃÜÂë´íÎó£¬ÇëÖØÐÂÊäÈë!!!\n"); 
		}
	}
    if( i == 3)
	{
        printf("µÇÂ¼Ê§°Ü!!!\n");
	}
	return 0;
}


//#include<stdio.h>
//#include<string.h>
//int main()
//{
//    int i = 0;
//	char password[10] = {0};
//	for(i=0;i<3;i++)                                            
//	{
//       printf("please enter you password £º ");
//	   scanf("%s", password);
//	   if( strcmp(password,"aa56")==0)
//	   {
//		   printf("your password is right\n");
//		   break;
//	   }
//	   else
//	   {
//		   if(i!=2)
//	       printf("\n");
//	   }
//	}
//
//	   if(i==3)
//	  {
//		printf(" µÇÂ¼Ê§°Ü\n");
//	   }
//	return 0;
//}