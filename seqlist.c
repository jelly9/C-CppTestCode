#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#pragma warning(disable:4996) 
#define MAXSIZE 200
typedef int ElemType;

typedef struct seqlist
{
	ElemType *data;
	int listlength;
	int listsize;
}seqlist;
void initlist( seqlist *L )
{
	L->data = ( ElemType* )malloc( MAXSIZE*sizeof(ElemType) );
	L->listlength = 0;
	L->listsize = MAXSIZE;
}
void insertelem(seqlist *L, int pos, ElemType e )
{
	int j = 0;
	for( j = L->listlength+1; j>pos; j--)
	{
		L->data[j] = L->data[j-1];
	}
	L->data[pos-1] = e;
	L->listlength++;
}
void printlist(seqlist *L)
{
	int i = 0;
	for( i = 0; i<L->listlength; i++)
	{
		printf("%d ", L->data[i]);
	}
	printf("\n");
}
int main()
{
	seqlist L;
	int i = 0;
	int n = 0;
	int len = 0;
	initlist(&L);
	printf("Please input length >: ");
	scanf("%d", &len);
	printf("Please input elem >:");
	for( i = 1; i<len+1; i++)
	{
		scanf("%d",&n);
		insertelem(&L,i,n);
	}
	printlist(&L);

	system("pause");
	return 0;
}