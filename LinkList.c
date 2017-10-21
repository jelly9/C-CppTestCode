#include "LinkList.h"

///////////////////////////////////////////////////
// 思考为什么要传递二级指针?                     //
//使用一级指针，调用函数时形参压栈，函数结束时，/
// 形参会随之释放，期间对其参数的所有操作都无效。//
///////////////////////////////////////////////////

 //初始化单链表
void InitList(PNode* pHead)
{
	assert(pHead);
	*pHead = NULL;
}

// 构建新节点
PNode BuyNode(DataType data)
{
	 //申请内存
	PNode pNewNode = (PNode)malloc(sizeof(Node));
	if(NULL == pNewNode)
	{
		perror("malloc");
		exit(1);
	}

	pNewNode->data = data;
	pNewNode->next = NULL;

	return pNewNode;
}

// 在链表尾部插入值为data的新结点
void PushBack(PNode* pHead, DataType data)
{
	PNode pCurNode = *pHead;

	assert(pHead);

	//链表为空则直接插入
	if(NULL == *pHead)
	{
		*pHead = BuyNode(data);
	}
	else
	{
		//否则寻找尾节点
		while(pCurNode->next)
		{
			pCurNode = pCurNode->next;
		}
		//插入
		pCurNode->next = BuyNode(data);
	}
}

// 删除链表的最后一个节点
void PopBack(PNode* pHead)
{
 	PNode pCurNode = *pHead;
	PNode pTailNode = NULL;

	assert(pHead);

	//若链表为空则返回
	if(NULL == *pHead)
	{
		return ;
	}
	//若只有一个节点
	else if(NULL == (*pHead)->next)
	{
		free(*pHead);
		*pHead = NULL;
	}
	else
	{
		//节点个数大于一
		//寻找倒数第二个节点
		while(pCurNode->next->next)
		{
			pCurNode = pCurNode->next;
		}
		pTailNode = pCurNode->next;//记录尾节点
		free(pTailNode);//释放尾节点
		pCurNode->next = NULL;
	}
}

// 在链表头部插入置为data的新节点
void PushFront(PNode* pHead, DataType data)
{
	PNode pNewHead = BuyNode(data);

	pNewHead->next = *pHead;
	*pHead = pNewHead;
}

// 删除链表的第一个结点//
void PopFront(PNode* pHead)
{
	PNode pDelNode = NULL;

	assert(pHead);

	if(NULL == *pHead)
	{
		return ; 
	}
	else
	{
		pDelNode = *pHead;
		*pHead = (*pHead)->next;
		free(pDelNode);
	}
}

// 查找链表中值为data的结点，存在返回该结点的地址，否则返回空
PNode Find(PNode pHead, DataType data)
{
	PNode pCurNode = pHead;

	//遍历查找
	while(pCurNode)
	{
		if(data == pCurNode->data)
		{
			return pCurNode;
		}
		pCurNode = pCurNode->next;
	}		

	return NULL;
}

//在链表pos位置后插入值为data的新节点
void Insert(PNode pos, DataType data)
{
	PNode pNewNode = NULL;

	if(NULL == pos)
	{
		return ;
	}

	pNewNode = BuyNode(data);
	pNewNode->next = pos->next;
	pos->next = pNewNode;
}

// 删除单链表pos位置上的结点
void Erase(PNode* pHead, PNode pos)
{
	PNode pPreNode = NULL;

	assert(pHead);

	if(NULL == *pHead || NULL == pos)
	{
		return ;
	}
	//若待删节点为头结点则特殊处理
	if(pos == *pHead)
	{
		(*pHead) = pos->next;
		free(pos);
	}
	//找到待删节点的下一个节点
	else
	{
		pPreNode = *pHead;
		while(pos != pPreNode->next)
		{
			pPreNode = pPreNode->next;
		}
		pPreNode->next = pos->next;
		free(pos);
	}
}

// 移除链表中第一个值为data的结点
void Remove(PNode* pHead, DataType data)
{
	assert(pHead);

	Erase(pHead, Find(*pHead, data));
}

// 移除链表中所有值为data的结点
void RemoveAll(PNode* pHead, DataType data)
{
	PNode pDelNode = NULL;
	PNode pPreNode = NULL;

	pPreNode = *pHead;
	pDelNode = (*pHead)->next;

	assert(pHead);

	//先从第二个节点开始处理
	while(pDelNode)
	{
		if(pDelNode->data == data)
		{
			pPreNode->next = pDelNode->next;
			free(pDelNode);
			pDelNode = pPreNode;
		}
		pPreNode = pDelNode;
		pDelNode = pDelNode->next;
	}

	//结束后再处理第一个节点
	if((*pHead)->data == data)
	{
		pDelNode = *pHead;
		*pHead = pDelNode->next;
		free(pDelNode);
	}
}

////////////////////////////////////////////

// 获取链表中结点的总个数
size_t Size(PNode pHead)
{
	size_t count = 0;
	PNode pCurNode = pHead;

	while(pCurNode)
	{
		count++;
		pCurNode = pCurNode->next;
	}

	return count;
}

// 获取链表中第一个结点
PNode Front(PNode pHead)
{
	return pHead;
}

// 获取链表中最后一个节点
PNode Back(PNode pHead)
{
	PNode pCurNode = pHead;

	//若为空直接返回
	if(NULL == pHead)
	{
		return NULL;
	}

	//不空则遍历
	else
	{
		while(pCurNode->next)
		{
			pCurNode = pCurNode->next;
		}
		return pCurNode;
	}
}

// 判断链表是否为空
int Empty(PNode pHead)
{
	if(NULL == pHead)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

// 打印单链表
void PrintList(PNode pHead)
{
	PNode pCurNode = pHead;

	while(pCurNode)
	{
		printf("%d->", pCurNode->data);
		pCurNode = pCurNode->next;
	}
	printf("NULL\n");
}

////////////////////链表面题///////////////////////////////

//逆序打印
void PrintListFromTail(PNode pHead)
{
	//递归
	if(pHead->next)
	{
		PrintListFromTail(pHead->next);
	}
	printf("%d->", pHead->data);
}

//删除非尾节点
void DelectNotTailNode(PNode* pHead, PNode pos)
{
	PNode posNextNode = NULL;

	if(NULL == pos || NULL == pos->next)
	{
		return;
	}
	//将待删节点后一个节点data域赋给待删节点，再删除后面的节点
	posNextNode = pos->next;
	pos->data = posNextNode->data;
	pos->next = posNextNode->next;
	free(posNextNode);
}

//在非头节点前插入
void InsertNotHeadNode(PNode pos, DataType data)
{
	PNode pNewNode = NULL;

	if(NULL == pos)
	{
		return ;
	}

	//插到该节点的后面，再将该节点与其交换
	pNewNode = BuyNode(pos->data);
	pNewNode->next = pos->next;
	pos->next = pNewNode;
	pos->data = data;
}


//判断两个链表是否相交
int IsListCross(PNode pHead1, PNode pHead2)
{
	PNode pTailNodeNode1 = pHead1;
	PNode pTailNodeNode2 = pHead2;

	if(NULL == pHead1 || NULL == pHead2)
	{
		return 0;
	}

	//分别找到两个链表的尾节点
	while(pTailNodeNode1->next)
	{
		pTailNodeNode1 = pTailNodeNode1->next;
	}

	while(pTailNodeNode2->next)
	{
		pTailNodeNode2 = pTailNodeNode2->next;
	}

	if(pTailNodeNode1 == pTailNodeNode2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//求两个链表的交点
PNode GetCrossNode(PNode pHead1, PNode pHead2)
{
	int gap = Size(pHead1) - Size(pHead2);
	PNode pCurNode1 = pHead1;
	PNode pCurNode2 = pHead2;
	
	//让长的链表先走
	if(IsListCross(pHead1, pHead2))
	{
		if(gap>0)
		{
			while(gap--)
			{
				pCurNode1 = pCurNode1->next;
			}
		}
		else
		{
			gap = -gap;
			while(gap--)
			{
				pCurNode1 = pCurNode1->next;
			}
		}
		
		while(pCurNode1 != pCurNode2)
		{
			pCurNode1 = pCurNode1->next;
			pCurNode2 = pCurNode2->next;
		}

		return pCurNode1;
	}
	else
	{
		return NULL;
	}
}


//判断链表是否带环,带环则返回相遇点
PNode HasCircle(PNode pHead)
{
	PNode pFast = pHead;
	PNode pSlow = pHead;

	while(pFast && pFast->next)
	{
		pSlow = pSlow->next;
		pFast = pFast->next->next;
		if(pSlow == pFast)
		{
			return pSlow;
		}
	}

	return NULL;
}

//求环的长度
size_t GetCircleLen(PNode pMeetNode)
{
	size_t count = 0;
	PNode pCurNode = pMeetNode;

	if(NULL == pMeetNode)
	{
		return 0;
	}
	 
	while(pCurNode != pMeetNode)
	{
		count++;
		pCurNode = pCurNode->next;
	}

	return count;
	
}

//求环的入口点
PNode GetEnterNode(PNode pHead, PNode pMeetNode)
{
	PNode pH = pHead;
	PNode pM = pMeetNode;

	if(NULL == pHead || NULL == pMeetNode)
	{
		return NULL;
	}

	while(pH != pM)
	{
		pH = pH->next;
		pM = pM->next;
	}
	return pH;
}

//判断两个链表是否相交，考虑带环情况
int HasCircleWithircle(PNode pHead1, PNode pHead2)
{
	PNode pL1 = pHead1;
	PNode pL2 = pHead2;

	PNode pCurNode = NULL;

	PNode pMeetNode1 = HasCircle(pHead1);
	PNode pMeetNode2 = HasCircle(pHead2);

	//两个都不带环
	if(NULL == pMeetNode1 && NULL == pMeetNode2)
	{
		while(pL1->next)
		{
			pL1 = pL1->next;
		}

		while(pL2->next)
		{
			pL2 = pL2->next;	
		}

		if(pL1 == pL2)
		{
			return 1;
		}
	}
	//两个都带环
	else if(pMeetNode1 && pMeetNode2)
	{
		pCurNode = pMeetNode1;
		while(pCurNode->next != pMeetNode1)
		{
			if(pCurNode == pMeetNode2)
			{
				return 2;
			}
			pCurNode = pCurNode->next;
		}
		if(pCurNode == pMeetNode2)
		{
			return 2;
		}
	}

	return 0;
}

//逆置链表
void Reverse(PNode* pHead)
{
	PNode pCurNode = *pHead;
	PNode pPreNode = NULL;
	PNode pNextNode = pCurNode->next;

	assert(pHead);

	while(pCurNode->next)
	{
		pCurNode->next = pPreNode;
		pPreNode = pCurNode;
		pCurNode = pNextNode;
		pNextNode = pNextNode->next;
	}

	pCurNode->next = pPreNode;
	*pHead = pCurNode;

}







