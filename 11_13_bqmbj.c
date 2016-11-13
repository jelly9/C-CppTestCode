#include <stdio.h>
#include <windows.h>


//公鸡一只5元母鸡一只3元小鸡一只1元100元买一百只鸡问公母小个买几只
int main()
{

	int x = 0;
	int y = 0;
	int z = 0;
	for( x = 0; x < 20; x++ ){//公鸡数
		for( y = 0; y < 33; y++ ){//母鸡数
			z = 100 - x - y;
			if( (100 == (5*x + 3*y + z/3)) && 0 == z%3 ){
				printf("公鸡:%d, 母鸡:%d, 小鸡:%d.\n",x, y, z);
			}
		}
	}

	system("pause");
	return 0;
}