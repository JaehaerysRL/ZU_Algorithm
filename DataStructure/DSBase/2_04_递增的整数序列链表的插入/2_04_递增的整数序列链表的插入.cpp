// 2_04_递增的整数序列链表的插入.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//本题要求实现一个函数，在递增的整数序列链表（带头结点）中插入一个新整数，并保持该序列的有序性。

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node* PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print(List L); /* 细节在此不表 */

List Insert(List L, ElementType X);

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

List Insert(List L, ElementType X) {
    List p, q, t;
    t = (List)malloc(sizeof(struct Node));
    t->Data = X;
    p = L;
    q = L->Next;
    int sig = 0;
    while (q) {
        if (X < q->Data) {
            p->Next = t;
            t->Next = q;
            sig = 1;
            break;
        }
        else {
            p = p->Next;
            q = q->Next;
        }
    }
    if (sig == 0) {
        t->Next = NULL;
        p->Next = t;
    }
    return L;
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
