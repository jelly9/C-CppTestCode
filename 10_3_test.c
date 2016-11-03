#include <stdio.h>
#include <windows.h>

int main()
{
	//char c1 = 129;
	//char c2 = -129;

	//printf("c1_d = %d\n", c1);
	//printf("c1_u = %u\n", c1);

	//printf("c1_d = %d\n", c2);
	//printf("c1_u = %u\n", c2);




	char           c1 = 394;
	unsigned char uc1 = 394;

	char           c2 = -394;
	unsigned char uc2 = -394;

	printf("c1-d   = %d\n", c1);
	printf("c1_u   = %u\n", c1);

	printf("u_c1_d = %d\n", uc1);
	printf("u_c1_u = %u\n", uc1);

	printf("c2_d   = %d\n", c2);
	printf("c2_u   = %u\n", c2);

	printf("u_c2_d = %d\n", uc2);
	printf("u_c2_u = %u\n", uc2);


	system("pause");
	return 0;
}