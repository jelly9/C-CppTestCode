#include <stdio.h>

typedef struct _ListNode {
    int val;
    _ListNode *next;
    _ListNode(int x) : val(x), next(NULL) {}
}ListNode;

void Swap(ListNode *n1, ListNode *n2){
    if(n1 == NULL || n2 == NULL){
        return;
    }
    int temp = n1->val;
    n1->val = n2->val;
    n2->val = temp;
}

void PrintList(ListNode *head){
    while(head != NULL){
        printf("%d->", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if(head == NULL){
            return NULL;

        }
        partionSort(head, NULL);
        return head;

    }
private:
    void partionSort(ListNode *left, ListNode *right){
        if(left == NULL || left == right || left->next == right){
            return;
        }
        ListNode *mid = partionSortCore(left, right);
        partionSort(left, mid);
        partionSort(mid->next, right);

    }

    ListNode *partionSortCore(ListNode *left, ListNode *right){
        if(left == NULL || left == right || left->next == right){
            return left;
        }

        ListNode *pKey = left;
        ListNode *pPre = left;
        ListNode *pCur = left->next;
        while(pCur != right){
            if(pCur->val < pKey->val && (pPre = pPre->next)!= pCur){
                Swap(pPre, pCur);
            }
            pCur = pCur->next;

        }

        Swap(pPre, pKey);
        return pPre;
    }

    //4,8,6,1,7,3,5
    //4,1,3,8,7,6,5
};

ListNode* SingleList(int a[], size_t size){
    if(size == 0){
        return NULL;
    }

    ListNode *pHead = new ListNode(a[0]);
    ListNode *pCur = pHead;
    for(size_t i = 1; i < size; i++){
        pCur->next = new ListNode(a[i]);
        pCur = pCur->next;
    }

    return pHead;
}

ListNode *partionList(ListNode *head, int x) {
    if(head == NULL){
        return NULL;
    }

    //1,4,3,2,5,2
    ListNode *pPre = head;
    while(pPre && pPre->val < x){
        pPre = pPre->next;
    }
    if(pPre == NULL){
        return head;
    }

    printf("pPre = %d\n", pPre->val);

    ListNode *pCur = pPre->next;
    while(pCur != NULL){
        if(pCur->val < x){
            Swap(pCur, pPre);
            pPre = pPre->next;
        }
        pCur = pCur->next;
    }
    return head;
}

int main(){
    const int N = 8;
    int a[N] = {6,4,3,9,10,8,5,7};
    ListNode *head = SingleList(a, N);
////////////////////////////
    PrintList(head);
    head = partionList(head, 10);
    PrintList(head);
////////////////////////////
//    Solution s;

//    PrintList(head);
//    s.sortList(head);
//    PrintList(head);

    return 0;
}
