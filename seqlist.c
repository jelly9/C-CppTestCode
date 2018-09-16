#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#pragma warning(disable:4996)

#define MAXSIZE 100
typedef int ElemType;


typedef struct seqlist
{
	ElemType *data;
	int listlength;
	int listsize;
}seqlist;


int Initlist( seqlist *L );//初始化顺序表
int Insertelem( seqlist *L, int pos, ElemType e );//在第pos个位置插入元素e
int Delectelem( seqlist *L, int pos, ElemType e );//删除
int Printlist( seqlist *L );//打印顺序表
int UpdateElem( seqlist *L,int pos,ElemType e );//替换一个元素
int ListLenght( seqlist *L );//返回元素个数
int ListSize( seqlist *L );//返回大小
ElemType Getelem( seqlist *L, int pos);//返回一个元素的值

//获取该位置元素的值
ElemType Getelem( seqlist *L, int pos)
{
	 if(pos <= 0 || pos > L->listlength+1)
    {
        printf("Error pos\n");
        exit(1);
    }
	 return L->data[pos-1];
}

//求顺序表大小
int ListSize( seqlist *L )
{
	return L->listsize;
}

//求长度
int ListLength( seqlist *L )
{
	return L->listlength;
}

//初始化线性表表
int Initlist( seqlist *L )
{
	printf("Start initseqlist...\n");
	L->data = ( ElemType* )malloc( MAXSIZE*sizeof(ElemType) );
	if( NULL == L->data){
		exit(1);
	}
	L->listlength = 0;
	L->listsize = MAXSIZE;
	printf("End initseqlist...\n");
	return 1;
}

//初始化元素
int Initelem(seqlist *L)
{
	int i = 0;
	int n = 0;
	int len = 0;
	printf("Start initelem...\n");
	printf("Please input length >: ");
	scanf("%d", &len);
	printf("Please input elem >:");
	for( i = 1; i<len+1; i++)
	{
		scanf("%d",&n);
		Insertelem( L, i, n );
	}
	printf("End initelem...\n");
	return 1;
}

//插入元素
int Insertelem(seqlist *L, int pos, ElemType e )
{
	int j = 0;
	if( L->listlength >= L->listsize ) //插入位置合法性检验
	{
		printf("List is full!\n");
		return 0;
	}
	 if(pos <= 0 || pos > L->listlength+1)
    {
        printf("Error pos\n");
        return 0;
    }
	for( j = L->listlength+1; j>pos-1; j--)
	{
		L->data[j] = L->data[j-1];
	}
	L->data[pos-1] = e;
	L->listlength++;
	return 1;
}

//打印顺序表
int Printlist(seqlist *L)
{
	int i = 0;
	printf("=====================\n");
	for( i = 0; i<L->listlength; i++)
	{
		printf("%4d", L->data[i]);
		if( 4 == i%5 )//格式控制，每行打印五个元素
			printf("\n");
	}
	if( 0 != i%5 )
			printf("\n");
	printf("\n length = %d\n",ListLength( L) );
	printf(" size = %d\n", ListSize( L ));
	printf("=====================\n");
	return 1;
}

//删除元素
int Delectelem( seqlist *L, int pos, ElemType e )
{
	int j = 0;
	if( L->listlength >= L->listsize ) {//合法性检验
		printf("List is full!\n");
		return 0;
	}
	 if(pos <= 0 || pos > L->listlength)
    {
        printf("Error pos\n");
        return 0;
    }
	e = L->data[pos-1];
	for( j = pos-1; j < L->listlength-1; j++ )
	{
		L->data[j] = L->data[j+1];
	}
	L->listlength--;
	return e;
}

//替换pos位置元素的值
int UpdateElem(seqlist *L,int pos,ElemType e)
{
    if(pos<1 || pos>L->listlength){
        printf("Error pos!\n");
        return 0;
    }
    L->data[pos-1] = e;
    return 1;
} 


void meun()//打印菜单
{

	printf("\n       Welcome      \n");
	printf("=====================\n");
	printf("--  1.Initlist.    --\n");
	printf("--  2.Initelem.    --\n");
	printf("--  3.Insertelem.  --\n");
	printf("--  4.Delectelem.  --\n");
	printf("--  5.UpdateElem.  --\n");
	printf("--  6.GetElem.     --\n");
	printf("--  0.Exit.        --\n");
	printf("=====================\n");

}

int main()
{
	int pos = 0;
	int e = 0;
	int select = 0;
	seqlist L;
	//Initlist(&L);
	do
	{
		Printlist(&L);
		meun();
		printf("Please select >:");
		scanf("%d", &select);
		switch(select)
		{
			case 1:Initlist(&L);break;

			case 2:Initelem(&L);break;

			case 3:printf("Please pos and elem:");
				scanf("%d %d", &pos, &e);
				Insertelem(&L, pos, e);
				break;

			case 4:printf("Please pos:");
				scanf("%d", &pos);
				printf("The elem %d was delected!\n", Delectelem( &L, pos,e ) );
				break;

			case 5:printf("Please pos and elem:");
				scanf("%d %d", &pos, &e);
				UpdateElem(&L, pos, e);
				break;

			case 6:printf("Please pos:");
				scanf("%d", &pos);
				printf("The elem is >: %d \n",Getelem( &L, pos ) );
				break;

			case 0:printf("Exit...\n");break;
			default:printf("Error select...\n");
		}
	}while(select);
	

	system("pause");
	return 0;
}