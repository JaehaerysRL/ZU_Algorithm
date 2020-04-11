// 6-6 学生成绩链表处理 (20分)
//本题要求实现两个函数，一个将输入的学生成绩组织成单向链表；另一个将成绩低于某分数线的学生结点从链表中删除。。
//输入样例：
//1 zhang 78
//2 wang 80
//3 li 75
//4 zhao 85
//0
//80

//输出样例：
//2 wang 80
//4 zhao 85

#include <stdio.h>
#include <stdlib.h>

struct stud_node {
     int    num;
     char   name[20];
     int    score;
     struct stud_node *next;
};

struct stud_node *createlist();
struct stud_node *deletelist( struct stud_node *head, int min_score );

int main()
{
    int min_score;
    struct stud_node *p, *head = NULL;

    head = createlist();
    scanf("%d", &min_score);
    head = deletelist(head, min_score);
    for ( p = head; p != NULL; p = p->next )
        printf("%d %s %d\n", p->num, p->name, p->score);

    return 0;
}

/* 你的代码将被嵌在这里 */
struct stud_node* createlist() {
    struct stud_node* p, * t, * h;
    p = (struct stud_node*)malloc(sizeof(struct stud_node));
    h = p;
    while (1)
    {
        t = (struct stud_node*)malloc(sizeof(struct stud_node));
        int a;
        scanf("%d", &a);
        if (a == 0) {
            p->next = NULL;
            break;
        }
        else {
            t->num = a;
            scanf("%s %d", t->name, &t->score);
            p->next = t;
            p = p->next;
        }
    }
    return h->next;
}

struct stud_node* deletelist(struct stud_node* head, int min_score) {
    struct stud_node* p, * t, * h;
    h = (struct stud_node*)malloc(sizeof(struct stud_node));
    h->next = head;
    p = h;
    t = head;
    while (t)
    {
        if (t->score < min_score) {
            p->next = t->next;
            free(t);
            t = t->next;
        }
        else {
            p = t;
            t = t->next;
        }
    }
    p->next = NULL;
    return h->next;
}