// 2_05_两个有序链表序列的合并.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//本题要求实现一个函数，将两个链表表示的递增整数序列合并为一个非递减的整数序列。

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
void Print(List L); /* 细节在此不表；空链表将输出NULL */

List Merge(List L1, List L2);

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
List Merge(List L1, List L2) {
    List p1 = L1, p2 = L2;
    List P = (List)malloc(sizeof(struct Node));
    List k = P;
    p1 = p1->Next;
    p2 = p2->Next;

    while (p1 && p2)
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
    k->Next = p1 ? p1 : p2;
    L1->Next = NULL;
    L2->Next = NULL;
    return P;
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
