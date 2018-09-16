#ifndef __LIST_H__
#define __LIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct Node{
    int data;
    struct Node *next;
};

typedef struct Node Node;
//获取链表尾节点
Node* get_tail(Node *pHead);
//申请链表节点
Node* create_node(int val);
//逆序打印单链表
void print_list_reverse(Node *head);
//顺序打印单链表
void print_list(Node *head);
//头插单链表
void push_front(Node **pHead, int val);
//查找倒数第k个节点
Node* find_k_to_tail(Node *pHead, int k);
//翻转单链表
void reverse_list(Node **pHead);
//合并两个有序单链表，使合并后的单链表依然有序
Node* merge_sortList(Node *pHead1, Node *pHead2);
//求两个链表的交点
Node* meeting_node(Node *pHead);
//求带环单链表的入口节点
Node* entry_node(Node *pHead);

#endif
