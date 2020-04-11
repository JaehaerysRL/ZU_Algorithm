// 6-9 链表拼接 (20分)
//本题要求实现一个合并两个有序链表的简单函数。链表结点定义如下：
//输入样例：
//1 3 5 7 -1
//2 4 6 -1
//输出样例：
//1 2 3 4 5 6 7 

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist(); /*裁判实现，细节不表*/
struct ListNode *mergelists(struct ListNode *list1, struct ListNode *list2);
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
    struct ListNode  *list1, *list2;

    list1 = createlist();
    list2 = createlist();
    list1 = mergelists(list1, list2);
    printlist(list1);
	
    return 0;
}

/* 你的代码将被嵌在这里 */
struct ListNode* mergelists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* p1 = list1,* p2 = list2;
    struct ListNode* P = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* k = P;
    while (p1 && p2)
    {
        if (p1->data < p2->data)
        {
            k->next = p1;
            k = p1;
            p1 = p1->next;
        }
        else
        {
            k->next = p2;
            k = p2;
            p2 = p2->next;
        }
    }
    k->next = p1 ? p1 : p2;
    return P->next;
}