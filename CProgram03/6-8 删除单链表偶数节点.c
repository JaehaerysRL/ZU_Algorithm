// 6-8 删除单链表偶数节点 (20分)
//本题要求实现两个函数，分别将读入的数据存储为单链表、将链表中偶数值的结点删除。链表结点定义如下：

//输入样例：
//1 2 2 3 4 5 6 7 -1

//输出样例：
//1 3 5 7 
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist();
struct ListNode *deleteeven( struct ListNode *head );
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
    struct ListNode *head;

    head = createlist();
    head = deleteeven(head);
    printlist(head);

    return 0;
}

/* 你的代码将被嵌在这里 */
struct ListNode* createlist() {
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

struct ListNode* deleteeven(struct ListNode* head) {

    struct ListNode* l, * h, * p, * oh, * op, * t;
    l = head->next;
    h = head;
    p = h;
    oh = (struct ListNode*)malloc(sizeof(struct ListNode));
    oh->next = NULL;
    op = oh;
    while (l) {
        if (l->data % 2 != 0) {
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
    head = head->next;
    oh = oh->next;
    return oh;
}