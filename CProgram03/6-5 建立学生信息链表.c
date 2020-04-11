// 6-5 建立学生信息链表 (20分)
//本题要求实现一个将输入的学生成绩组织成单向链表的简单函数。
//输入样例：
//1 zhang 78
//2 wang 80
//3 li 75
//4 zhao 85
//0
//输出样例：
//1 zhang 78
//2 wang 80
//3 li 75
//4 zhao 85

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stud_node {
     int    num;
     char   name[20];
     int    score;
     struct stud_node *next;
};
struct stud_node *head, *tail;

void input();

int main()
{
    struct stud_node *p;
	
    head = tail = NULL;
    input();
    for ( p = head; p != NULL; p = p->next )
        printf("%d %s %d\n", p->num, p->name, p->score);

    return 0;
}

/* 你的代码将被嵌在这里 */
void input() {
    struct stud_node* p, * t;
    p = (struct stud_node*)malloc(sizeof(struct stud_node));
    head = p;
    while (1)
    {
        t = (struct stud_node*)malloc(sizeof(struct stud_node));
        int a;
        scanf("%d", &a);
        if (a == 0) {
            tail = p;
            tail->next = NULL;
            break;
        }
        else {
                t->num = a;
                scanf("%s %d", t->name, &t->score);
                p->next = t;
                p = p->next;   
        }
    }
    head = head->next;
}
