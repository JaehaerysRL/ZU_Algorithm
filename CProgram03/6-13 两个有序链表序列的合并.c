// 6-13 两个有序链表序列的合并 (15分)
//本题要求实现一个函数，将两个链表表示的递增整数序列合并为一个非递减的整数序列。

//输入样例：
//3
//1 3 5
//5
//2 4 6 8 10

//输出样例：
//1 2 3 4 5 6 8 10 
//NULL
//NULL

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
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */
List Merge( List L1, List L2 ){
    List p1 = L1, p2 = L2;
    List P = (List)malloc(sizeof(struct Node));
    List k = P;
    p1 = p1->Next;
    p2 = p2->Next;
    
    while(p1&&p2)
    {
        if (p1->Data < p2->Data)
        {
            k->Next = p1;
            k = p1;
            p1 = p1->Next;
        }
        else
        {
            k->Next = p2;
            k = p2;
            p2 = p2->Next;
        }
    }
    k->Next=p1?p1:p2;
    L1->Next=NULL;
    L2->Next=NULL;
    return P;
}