#include "effic.h"

int main()
{
	int select = 0;
	meun();
	do
	{
		printf("Please select:");
		scanf("%d", &select);
		switch(select)
		{
		case 1:test();
			meun();
			break;
		case 0:printf("Exit...\n");
			break;
		default:printf("Error select!\n");
		}
	}
	while(select);

	
	return 0;
}