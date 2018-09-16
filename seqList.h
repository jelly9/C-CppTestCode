#ifndef __SEQLIST__
#define __SEQLIST__

#include <stdio.h>
#include <windows.h>
#include <assert.h>

#pragma warning(disable:4018)
#pragma warning(disable:4996)

typedef int DataType;

#define CAPACITY 0
#define INCREASMENT 1

typedef struct SeqList
{
	DataType *data;//数据域
	size_t size;   //有效数据元素的个数
	size_t cap; //顺序表容量
}SeqList;

// 初始化顺序表
void InitSeqList(SeqList* pSeq);

// 摧毁顺序表
void DestroySeqList(SeqList* pSeq);

// 打印线性表
void PrintSeqList(SeqList* pSeq);

// 在顺序表的尾部插入值为data的元素
void PushBack(SeqList* pSeq, DataType _data);

// 自增
int IncSeqList(SeqList* pSeq);

// 判满
int IsFull(SeqList* pSeq);

// 判空
int IsEmpty(SeqList* pSeq);

// 求当前有效元素个数
int SizeSeqList(SeqList* pSeq);

//求容量
int CapSeqList(SeqList* pSeq);

// 删除顺序表的最后一个元素
void PopBack(SeqList* pSeq);

// 在顺序表的头部插入值为data的元素
void PushFront(SeqList* pSeq, DataType data);

// 删除顺序表头部元素
void PopFront(SeqList* pSeq);

// 在顺序表中pos位置上插入值为data的元素
void Insert(SeqList* pSeq, size_t pos, DataType data);

// 删除顺序表中pos位置上的元素
void Erase(SeqList* pSeq, size_t pos);

// 在顺序表中查找值为data的元素，找到返回该元素的位置，否则返回-1
int Find(SeqList* pSeq, DataType data);

// 删除顺序表中第一个值为data的元素
void Remove(SeqList* pSeq, DataType data);

// 删除顺序表中所有值为data的元素
void RemoveAll(SeqList* pSeq, DataType data);

// 使用冒泡排序给顺序表中的元素排序
void BubbleSort(SeqList* pSeq);

// 使用选择排序给顺序表中的元素排序
void SelectSort(SeqList* pSeq);

// 使用二分查找在顺序表中查找值为data
int BinarySearch(SeqList* pSeq, DataType data);




#endif

