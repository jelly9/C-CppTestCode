#include <stdio.h>
#include <windows.h>
#include <assert.h>

#define INIT_CAP 64

typedef int elemtype;

typedef struct seqList
{
	elemtype *elem;//元素数组
	int size;//当前大小
	int cap;//容量
}seqList;

//初始化线性表
void initList(seqList *L)
{
	assert(L);

	L->elem = (elemtype*)malloc(INIT_CAP * sizeof(elemtype));//申请内存空间
	if(NULL == L)//检测
	{
		perror("malloc");
		exit(1);
	}

	L->size = 0;//初始化大小
	L->cap = INIT_CAP;//初始化容量
}

void insertList(seqList *L, elemtype e)
{
	assert(L);

	L->elem[L->size] = e;
	L->size++;
}

void printList(seqList *L)
{
	int i = 0;

	assert(L);

	for(; i < L->size; i++)
	{
		printf("%d  ", L->elem[i]);
	}
	printf("\n");

}

void reversePrint(seqList *L, int s)
{
	
	if(s)
	{
		reversePrint(L, s-1);
	}
	printf("%d  ", L->elem[s]);
}

int main()
{
	int i = 0;
	seqList L;
	initList(&L);

	for(i = 0; i < 5; i++)
	{
		insertList(&L, i);
	}

	printList(&L);
	reversePrint(&L, 5);
	system("pause");
	return 0;
}