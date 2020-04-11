// 6-10 统计专业人数 (15分)
//本题要求实现一个函数，统计学生学号链表中专业为计算机的学生人数。

//输入样例：
//1021202
//2022310
//8102134
//1030912
//3110203
//4021205
//#
//输出样例：
//3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    char code[8];
    struct ListNode *next;
};

struct ListNode *createlist(); /*裁判实现，细节不表*/
int countcs( struct ListNode *head );

int main()
{
    struct ListNode  *head;

    head = createlist();
    printf("%d\n", countcs(head));
	
    return 0;
}

/* 你的代码将被嵌在这里 */
int countcs(struct ListNode* head) {
    int count = 0;
    struct ListNode* p = head;
    while (p)
    {
        if (p->code[1] == '0' && p->code[2] == '2')count++;
        p=p->next;
    }
    return count;
}