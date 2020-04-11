// 6-3 奇数值结点链表 (20分)
//本题要求实现两个函数，分别将读入的数据存储为单链表、将链表中奇数值的结点重新组成一个新的链表。链表结点定义如下：

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *readlist();
struct ListNode *getodd( struct ListNode **L );
void printlist( struct ListNode *L )
{
     struct ListNode *p = L;
     while (p) {
           printf("%d ", p->data);
           p = p->next;
     }
     printf("\n");
}

int main()
{
    struct ListNode *L, *Odd;
    L = readlist();
    Odd = getodd(&L);
    printlist(Odd);
    printlist(L);

    return 0;
}

/* 你的代码将被嵌在这里 */
struct ListNode* readlist() {
    struct ListNode* p, * L, * t;
    L = (struct ListNode*)malloc(sizeof(struct ListNode));
    L->next = NULL;
    L->data = 0;
    p = L;  
    while (1) {
        t = (struct ListNode*)malloc(sizeof(struct ListNode));
        scanf("%d", &t->data);
        if (t->data == -1) break;
        p->next = t;
        p = t;
    }
    p->next = NULL;
    return L;
}

struct ListNode* getodd(struct ListNode** L) {
    struct ListNode* l, * h, * p, * oh, * op, * t;
    l = (*L)->next;
    h = *L;
    p = h;
    oh = (struct ListNode*)malloc(sizeof(struct ListNode));
    oh->next = NULL;
    op = oh;
    while (l) {
        if (l -> data % 2 != 0) {
            op->next = l;
            op = op->next;
            p->next = l->next;
        }
        else {
            p = p->next;
        }
        l = l->next;
    }
    op->next = NULL;
    p->next = NULL;
    *L = (*L)->next;
    oh = oh->next;
    return oh;
}