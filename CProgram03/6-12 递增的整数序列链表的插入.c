// 6-12 递增的整数序列链表的插入 (15分)
//本题要求实现一个函数，在递增的整数序列链表（带头结点）中插入一个新整数，并保持该序列的有序性。

//输入样例：
//5
//1 2 4 5 6
//3

//输出样例：
//1 2 3 4 5 6 

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表 */

List Insert( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    L = Read();
    scanf("%d", &X);
    L = Insert(L, X);
    Print(L);
    return 0;
}

/* 你的代码将被嵌在这里 */
List Insert( List L, ElementType X )
{
    List head = L;///头结点 无信息
    L = L->Next;///转到第一个结点
    List p = (List)malloc(sizeof(struct Node));
    p->Data = X;
    p->Next = NULL;
    List q = head;///初始为头结点
    if(L == NULL)///空链表
    {
        head->Next = p;
        return head;
    }
    while(L->Data < X)
    {
        q = L;
        L = L->Next;
        if(L->Next == NULL)///链表尾
        {
            L->Next = p;
            return head;
        }
    }
    p->Next = L;//插在中间
    q->Next = p;
    return head;
}