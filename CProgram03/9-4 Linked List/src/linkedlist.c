// 9-4 Linked List (20分)
//编写一个存放int的链表，链表用以下的数据类型表示：
//typedef struct _node Node;
//typedef struct {
//    Node *head;
//    Node *tail;
//} List;
 
//这个库要提供以下API函数：

//List list_create();
//void list_free(List *list);

//void list_append(List *list, int v);
//void list_insert(List *list, int v);

//void list_set(List *list, int index, int v);
//int list_get(List *list, int index);

//int list_size(List *list);

//int list_find(List *list, int v);
//void list_remove(List *list, int v);

//void list_iterate(List *list, void (*func)(int v));
//List list_create(); 创建一个List，其中的head和tail都是零。
//void list_free(List *list); 释放整个链表中全部的结点，list的head和tail置零。
//void list_append(List *list, int v); 用v制作新的结点加到链表的最后。
//void list_insert(List *list, int v); 用v制作新的结点加到链表的最前面。
//void list_set(List *list, int index, int v); 将链表中第index个结点的值置为v，链表结点从零开始编号。
//int list_get(List *list, int index); 获得链表中第index个结点的值，第一个结点的index为零。
//int list_size(List *list); 给出链表的大小。
//int list_find(List *list, int v); 在链表中寻找值为v的结点，返回结点的编号，结点的编号从零开始；如果找不到，返回-1。
//void list_remove(List *list, int v); 删除链表中值为v的结点。
//void list_iterate(List list, void (func)(int v)); 遍历链表，依次对每一个结点中的值做func函数。
//你的提交应该在src下有linkedlist.h和linkedlist.c两个文件，Node不能在linkedlist.h中声明。
//在本地测试时，如果使用Windows，可以用mingw32-make来执行Makefile完成编译，编译产生的是test.exe，用命令行执行时，必须加命令行参数来指定输出测试结果的文件名，如：test 123.txt

#include<stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

List list_create() {
    List* L = (List*)malloc(sizeof(List));
    L->head = NULL;
    L->tail = NULL;
    return *L;
}
void list_free(List* list) {
	QSD* p = list->head, * q;
    while (p)
    {
        q = p;
        p = p->next;
        free(q);
    }
    list->head = NULL;
    list->tail = NULL;
}

void list_append(List* list, int v) {
    QSD* a = (QSD*)malloc(sizeof(QSD));
    a->value = v;
    if (!list->head) {
        list->head = a;
        list->tail = a;
    }
    else {
        list->tail->next = a;
        list->tail = a;
    }
	list->tail->next = NULL;
}
void list_insert(List* list, int v) {
    QSD* a = (QSD*)malloc(sizeof(QSD));
    a->value = v;
    a->next = list->head;
    list->head = a;
    if(!list->tail) list->tail = a;
	list->tail->next = NULL;
}

void list_set(List* list, int index, int v) {
    QSD* p = list->head;
    for (int i = 0; i < index; i++)
    {
        p = p->next;
    }
    p->value = v;
}
int list_get(List* list, int index) {
    QSD* p = list->head;
    for (int i = 0; i < index; i++)
    {
        p = p->next;
    }
    return p->value;
}

int list_size(List* list) {
    QSD* p = list->head;
    int count = 0;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}

int list_find(List* list, int v) {
    int sig = -1, index = 0;
    QSD* p = list->head;
    while (p)
    {
        if (p->value == v) {
            sig = index;
            break;
        }
        else {
            p = p->next;
            index++;
        }
    }
    return sig;
}
void list_remove(List* list, int v) {
    QSD* p = list->head, * q = p->next;
    if (p->value == v) {
        if (q) {
            list->head = q;
            free(p);
        }
        else {
            list->head = NULL;
            list->tail = NULL;
        }
    }
    else {
        while (q)
        {
            if (q->value == v) {
                p->next = q->next;
                if (!q->next) {
                    list->tail = p;
                }
                free(q);
                break;
            }
            else {
                p = p->next;
                q = q->next;
            }
        }
    }
}

void list_iterate(List* list, void (*func)(int v)) {
    QSD* p = list->head;
    while (p)
    {
        func(p->value);
        p = p->next;
    }
}