
#include "list.h"

int main()
{
    Node *pHead = NULL;
    push_front(&pHead ,9);
    push_front(&pHead ,7);
    push_front(&pHead ,6);
    push_front(&pHead ,5);
    push_front(&pHead ,3);
    push_front(&pHead ,1);
    print_list(pHead);

    Node *pTail = get_tail(pHead);
    printf("%d\n", pTail->data);
    pTail->next = pHead->next->next;

    Node *meet = meeting_node(pHead);
    printf("%d\n", meet->data);

    Node *enterNode = entry_node(pHead);
    printf("%d\n", enterNode->data);
    
//    Node *pHead1 = NULL;
//    push_front(&pHead1 ,8);
//    push_front(&pHead1 ,7);
//    push_front(&pHead1 ,4);
//    push_front(&pHead1 ,2);
//    print_list(pHead1);
//
//    Node *newList = merge_sortList(pHead, pHead1);
//    print_list(newList);

//    print_list_reverse(pHead);
//    printf("%d\n", find_k_to_tail(pHead, 3)->data);
//
//    reverse_list(&pHead);
//    print_list(pHead);

    return 0;
}
