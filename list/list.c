#include "list.h"


Node* get_tail(Node *pHead)
{
    if(pHead == NULL)
        return NULL;
    while(pHead->next != NULL)
        pHead = pHead->next;

    return pHead;
}

Node* create_node(int val)
{
    Node *ret = (Node*)malloc(sizeof(Node));
    ret->data = val;
    ret->next = NULL;
    return ret;
}

void print_list_reverse(Node *head)
{
    if(head != NULL){
        if(head->next != NULL)
            print_list_reverse(head->next);
        printf("%d ", head->data);
    }
}

void print_list(Node *head)
{
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void push_front(Node **pHead, int val)
{
    if(pHead == NULL)
        return;

    if(*pHead == NULL){
        *pHead = create_node(val);
        (*pHead)->next = NULL;
        return;
    }

    Node *cur = create_node(val);
    cur->next = *pHead;
    *pHead = cur;
}

Node* find_k_to_tail(Node *pHead, int k)
{
    if(pHead == NULL || k <= 0)
        return NULL;

    Node *fast = pHead;
    int i = 0;
    for(; i < k-1; ++i){
        fast = fast->next;
        if(fast == NULL)
            return NULL;
    }

    Node *slow = pHead;
    while(fast->next != NULL){
        fast = fast->next;
        slow = slow->next;
    }
    
    return slow;
}

void reverse_list(Node **pHead)
{
    if(pHead == NULL)
        return;

    Node *pre = NULL;
    Node *cur = *pHead;
    Node *next = NULL;

    while(cur->next != NULL){
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    cur->next = pre;
    *pHead = cur;
}

Node* merge_sortList(Node *pHead1, Node *pHead2)
{
    if(pHead1 == NULL)
        return pHead2;
    if(pHead2 == NULL)
        return pHead1;

    Node *pNewHead = NULL;
    if(pHead1->data < pHead2->data){
        pNewHead = pHead1;
        pNewHead->next = merge_sortList(pHead1->next, pHead2);
    }else{
        pNewHead = pHead2;
        pNewHead->next = merge_sortList(pHead1, pHead2->next);
    }

    return pNewHead;
}

Node* meeting_node(Node *pHead)
{
    if(pHead == NULL)
        return NULL;

    Node *fast = pHead->next;
    if(fast->next != NULL)
        fast = fast->next;
    Node *slow = pHead->next;

    while(fast != NULL && slow != NULL){
        if(fast == slow)
            return fast;

        slow = slow->next;
        fast = fast->next;
        if(fast != NULL)
            fast = fast->next;
    }

    return NULL;
}

Node* entry_node(Node *pHead)
{
    if(pHead == NULL)
        return NULL;

    Node *meetNode = meeting_node(pHead);
    if(meetNode == NULL)
        return NULL;

    Node *cur = pHead;
    while(cur != meetNode){
        cur = cur->next;
        meetNode = meetNode->next;
    }

    return cur;
}
