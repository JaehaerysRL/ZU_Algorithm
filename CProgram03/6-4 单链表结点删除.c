// 6-4 单链表结点删除 (20分)
//本题要求实现两个函数，分别将读入的数据存储为单链表、将链表中所有存储了某给定值的结点删除。链表结点定义如下：

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *readlist();
struct ListNode *deletem( struct ListNode *L, int m );
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
    int m;
    struct ListNode *L = readlist();
    scanf("%d", &m);
    L = deletem(L, m);
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

struct ListNode* deletem(struct ListNode* L, int m) {
    struct ListNode* h, * p, * t;
    h = L;
    t = L;
    p = L->next;
    while (p)
    {
        if (p->data == m) {
            t->next = p->next;
            free(p);
            p = t->next;
        }
        else {
            p = p->next;
            t = t->next;
        }
    }
    return h->next;
}