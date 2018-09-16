#ifndef __LINKLIST2__
#define __LINKLIST2__

#include <stdio.h>
#include <windows.h>
#include <assert.h>

#pragma warning(disable:4996)

//实现无头复杂链表的如下操作

typedef int DataType;

typedef struct Node
{
	struct Node* next;
	struct Node* randem;
	DataType data;
}Node, *PNode;

//复杂链表的复制。一个链表的每个节点，有一个next指针\
指向下一个节点，还有一个random指针指向链表中一个随机\
节点或NULL，现要求复制这个链表，返回复制后的链表。
PNode CopyComplexList(PNode pHead1);

#endif