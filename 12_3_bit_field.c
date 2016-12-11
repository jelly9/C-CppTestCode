#include <stdio.h>
#include <windows.h>
#include <stddef.h>

//#pragma pack(8)

typedef unsigned int uint;
typedef unsigned char uchar;

//struct A
//{
//	char k : 7;
//	short j : 15;//4
//	short m : 15;//4
//	uint n : 31;
//	//uchar e : 7;//8
//	//uchar f : 5;//8
//	//uchar g : 4;
//	//uchar h : 3;//8    3
//	//uchar i : 7;//32     16
//	//uint a : 7;
//	//uint b : 6;//32
//	//uint c : 22;//32
//	//uint d : 12;//32     12
//	//uchar i : 7;//32     16
//}obj1;

struct A
{
	char a;
	int b;
	double c;
	
}obj1;
struct B
{
	int b;
	double c;
	char a;
}obj2;


int main()
{
	printf("%d\n", sizeof(obj1));//16
	printf("%d\n", sizeof(obj2));//24
	

	//printf("%d\n", sizeof(obj2));
	//printf("%d\n", offsetof(struct B, c));

	system("pause");
	return 0;
}