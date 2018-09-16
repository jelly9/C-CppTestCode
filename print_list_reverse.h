#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* create_node(int val)
{
    struct Node *ret = (struct Node*)malloc(sizeof(struct Node));
    ret->data = val;
    ret->next = NULL;
    return ret;
}

void print_list_reverse(struct Node *head)
{
    if(head == NULL){
        return;
    }

    print_list_reverse(head->next);
    printf("%d ", head->data);
}


int print_list_reverse()
{
    struct Node *head = create_node(1);
    struct Node *cur = head;
    cur->next = create_node(2);
    cur = cur->next;
    cur->next = create_node(3);
    cur = cur->next;
    cur->next = create_node(4);
    cur = cur->next;
    cur->next = create_node(5);

    print_list_reverse(head);

    return 0;
}
