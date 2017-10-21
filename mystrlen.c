#include <stdio.h>

int mystrlen(char *str )
{
	int len = 0;
	//for( ; *str != '\0'; *str++ )
	while( *str++ /*!= '\0'*/ )
	{
		len++;
	}
	return len;
}

int main()
{
	char *str = "Hello world!";
	printf("len = %d\n", mystrlen(str));

	getchar();
	return 0;
}

