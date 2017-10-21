#include<stdio.h> 

int main()
{ 
    int ch = 0;    
    int left = 0;  
    int right = 0;  
    printf("«Î ‰»Î“ª∂Œ◊÷∑˚:\n");  
    while((ch=getchar())!=EOF)
	{  
  
        if(ch=='{')
		{  
            left++;  
        }  
        if(ch=='}')
		{  
            if(left>right)
			{  
                right++;  
            }
			else
			{
                printf("∆•≈‰ ß∞‹!\n");  
                return 0;  
            }  
        }  
    }   
    if(right==left){  
        printf("∆•≈‰≥…π¶!\n");  
    }else{  
        printf("∆•≈‰ ß∞‹!\n");  
    }  
    return 0;  
}  

