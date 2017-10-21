#include "seqList.h"

void Test1(SeqList* pSeq)
{
	PopBack(pSeq);
	PushBack(pSeq, 9);
	PushBack(pSeq, 1);
	PushBack(pSeq, 9);
	PushBack(pSeq, 3);
	PushBack(pSeq, 5);
	PushBack(pSeq, 9);
	PushBack(pSeq, 7);
	PushBack(pSeq, 9);
	PrintSeqList(pSeq);//1 3 5 7 9

	RemoveAll(pSeq,9);
	//printf("Number: %d\n", Find(pSeq,91));
	PrintSeqList(pSeq);//1 3 5 7 9
}

void Test2(SeqList* pSeq)
{
	PopFront(pSeq);
	PushFront(pSeq,1);
	PushFront(pSeq,3);
	PushFront(pSeq,5);
	PushFront(pSeq,7);
	PushFront(pSeq,9);
	PrintSeqList(pSeq);//9 7 5 3 1
	PopFront(pSeq);
	PrintSeqList(pSeq);//7 5 3 1
	PopFront(pSeq);
	PrintSeqList(pSeq);//5 3 1
	PopFront(pSeq);
	PrintSeqList(pSeq);//3 1
	PopFront(pSeq);
	PrintSeqList(pSeq);//1
	PopFront(pSeq);	
	PopFront(pSeq);//Is empty!
}

void Test3(SeqList* pSeq)
{
	printf("IsEmpty: %d, IsFull: %d, Capacity: %d, size: %d\n", IsEmpty(pSeq), \
		IsFull(pSeq),CapSeqList(pSeq), SizeSeqList(pSeq));

	PopBack(pSeq);

	PushBack(pSeq, 7);
	PushBack(pSeq, 9);
	PushBack(pSeq, 1);
	PushBack(pSeq, 9);
	PushBack(pSeq, 3);
	PushBack(pSeq, 5);
	PushBack(pSeq, 9);
	PushBack(pSeq, 7);
	PushBack(pSeq, 9);

	PrintSeqList(pSeq);

	RemoveAll(pSeq,9);

	PrintSeqList(pSeq);

	printf("IsEmpty: %d, IsFull: %d, Capacity: %d, size: %d\n", IsEmpty(pSeq), \
		IsFull(pSeq),CapSeqList(pSeq), SizeSeqList(pSeq));
	


}

void Test4(SeqList* pSeq)
{
	printf("IsEmpty: %d, IsFull: %d, Capacity: %d, size: %d\n", IsEmpty(pSeq), \
		IsFull(pSeq),CapSeqList(pSeq), SizeSeqList(pSeq));

	PushBack(pSeq, 1);
	PushBack(pSeq, 3);
	PushBack(pSeq, 5);
	PushBack(pSeq, 7);
	PushBack(pSeq, 9);
	PushBack(pSeq, 10);
	PushBack(pSeq, 8);
	PushBack(pSeq, 6);
	PushBack(pSeq, 4);
	PushBack(pSeq, 2);

	PrintSeqList(pSeq);
	SelectSort(pSeq);
	PrintSeqList(pSeq);

	printf("pos: %d\n", BinarySearch(pSeq, 3));
	printf("pos: %d\n", BinarySearch(pSeq, 10));

	printf("IsEmpty: %d, IsFull: %d, Capacity: %d, size: %d\n", IsEmpty(pSeq), \
		IsFull(pSeq),CapSeqList(pSeq), SizeSeqList(pSeq));
}

int main()
   {
	SeqList seq;
	InitSeqList(&seq);

	//Test1(&seq);
	//Test2(&seq);
	//Test3(&seq);
	Test4(&seq);
	
	DestroySeqList(&seq);
	printf("\n");
	system("pause");
	return 0;
}