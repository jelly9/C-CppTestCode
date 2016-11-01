#include "effic.h"

int main()
{
	int start1 = 0, end1   = 0;
	int start2 = 0, end2   = 0;
	int start3 = 0, end3   = 0;
	int i = 0, j = 0;
	printf("Start test ...\n");

#if DEBUG1//²âÊÔÒ»
	start1 = GetTickCount();
	for(i = 0; i<CONDITION1; i++)
	{
		for(j = 0; j<CONDITION2; j++){
			//reverse_bit1( i ); 
			printf("test1...\n");
		}
	}
	end1 = GetTickCount();
#endif

#if DEBUG2//²âÊÔ¶ş
	start2 = GetTickCount();
	for(i = 0; i<CONDITION2; i++)
	{
		for(j = 0; j<CONDITION1; j++){
			//reverse_bit2( i );
			printf("test2...\n");
		}
	}
	end2 = GetTickCount();
#endif

#if DEBUG3//²âÊÔÈı
	start3 = GetTickCount();
	for(i = 0; i<CONDITION; i++)
	{

	}
	end3 = GetTickCount();
#endif	
	
#if DEBUG1
	printf( "Time of test1: %d\n", end1 - start1 );
#endif
#if DEBUG2
	printf( "Time of test2: %d\n", end2 - start2 );
#endif
#if DEBUG3
	printf( "Time of test3: %d\n", end3 - start3 );
#endif
	
	printf("End test ...\n");
	system("pause\n");
	return 0;
}