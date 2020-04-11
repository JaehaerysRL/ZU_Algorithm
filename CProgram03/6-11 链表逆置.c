// 6-11 链表逆置 (20分)
//本题要求实现一个函数，将给定单向链表逆置，即表头置为表尾，表尾置为表头。

//输入样例：
//1 2 3 4 5 6 -1

//输出样例：
//6 5 4 3 2 1 

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist(); /*裁判实现，细节不表*/
struct ListNode *reverse( struct ListNode *head );
void printlist( struct ListNode *head )
{
     struct ListNode *p = head;
     while (p) {
           printf("%d ", p->data);
           p = p->next;
     }
     printf("\n");
}

int main()
{
    struct ListNode  *head;

    head = createlist();
    head = reverse(head);
    printlist(head);
	
    return 0;
}

/* 你的代码将被嵌在这里 */
struct ListNode* reverse(struct ListNode* head) {
    struct ListNode* p, * t, * h, * q;
    p = (struct ListNode*)malloc(sizeof(struct ListNode));
    p->next = NULL;
    h = p;
    t = head;
    q = head->next;
    while (t)
    {
        q = t->next;
        t->next = p->next;
        p->next = t;
        t = q;
    }
    return h->next;
}