// 6-7 逆序数据建立链表 (20分)
//本题要求实现一个函数，按输入数据的逆序建立一个链表。
//输入样例：
//1 2 3 4 5 6 7 -1
  
//输出样例：
//7 6 5 4 3 2 1 

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist();

int main()
{
    struct ListNode *p, *head = NULL;

    head = createlist();
    for ( p = head; p != NULL; p = p->next )
        printf("%d ", p->data);
    printf("\n");

    return 0;
}

/* 你的代码将被嵌在这里 */
struct ListNode* createlist() {
    struct ListNode* p, * t, * h;
    p = (struct ListNode*)malloc(sizeof(struct ListNode));
    p->next = NULL;
    h = p;
    while (1)
    {
        t= (struct ListNode*)malloc(sizeof(struct ListNode));
        int a;
        scanf("%d", &a);
        if (a == -1) {
            break;
        }
        else {
            t->data = a;
            t->next = p->next;
            p->next = t;
        }
    }
    return h->next;
}
