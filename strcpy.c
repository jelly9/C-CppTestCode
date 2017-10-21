#include <stdio.h>
#include <windows.h>


char mystrcpy(char *dest, const char *src)
{
	while( *dest++ = *src++){
		;
	}
	return dest;
}

int main()
{
	char *str1 = "\0" ;
	char *str2 = "Hello bit!";
	mystrcpy(str1, str2);
	printf("%s\n", str1);

	system("pause");
	return 0;
}