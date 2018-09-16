#include <stdio.h>
#include <assert.h>
#include <windows.h>

#pragma warning(disable:4996)

char *reverse( char str[], int l, int r)
{
	assert(str);
	while( l < r )
	{
		str[l] ^= str[r];
		str[r] ^= str[l];
		str[l] ^= str[r];
		l++;
		r--;
	}

	return str;
}


char *leftrevolve(char str[], int n)
{
	int len = strlen(str);
	assert(str);
	assert( n>=0 && n<=len );
	reverse(str, 0, len-1);
	reverse(str, 0, len-n-1);
	reverse(str, len-n, len-1);
	return str;
}

int main()
{
	int n = 0;
	char str[100] = "ABCDEFG";
	scanf("%d", &n);

	printf("×óĞı%d¸ö×Ö·ûºó: %s\n", n, leftrevolve(str, n) );

	system("pause");
	return 0;
}