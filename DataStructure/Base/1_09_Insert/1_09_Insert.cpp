// 1_09_Insert.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 习题1.9 有序数组的插入 (20分)
// L是用户传入的一个线性表，其中ElementType元素可以通过>、==、<进行比较，并且题目保证传入的数据是递减有序的。
// 函数Insert要将X插入Data[]中合适的位置，以保持结果依然有序（注意：元素从下标0开始存储）。
// 但如果X已经在Data[]中了，就不要插入，返回失败的标记false；如果插入成功，则返回true。
// 另外，因为Data[]中最多只能存MAXSIZE个元素，所以如果插入新元素之前已经满了，也不要插入，而是返回失败的标记false。


#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
typedef enum { false, true } bool;
typedef int ElementType;

typedef int Position;
typedef struct LNode* List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};
List ReadInput(); /* 裁判实现，细节不表。元素从下标0开始存储 */
void PrintList(List L); /* 裁判实现，细节不表 */

//函数主体
bool Insert(List L, ElementType X) {
    bool judge = false;
    ElementType Left, Right, Loc;
    Left = 0;
    Right = L->Last;
    if ((L->Last + 1) < MAXSIZE) {
        while (Left <= Right) {
            Loc = (Left + Right) / 2;
            if (L->Data[Loc] > X) Left = Loc + 1;
            else if (L->Data[Loc] < X) Right = Loc - 1;
            else break;
        }
        if (Left > Right) {
            for (int i = L->Last; i >= Left; i--)
            {
                L->Data[i + 1] = L->Data[i];
            }
            L->Data[Left] = X;
            L->Last++;
            judge = true;
        }
    }
    return judge;
} 



int main()
{
    List L;
    ElementType X;

    L = ReadInput();
    scanf("%d", &X);
    if (Insert(L, X) == false)
        printf("Insertion failed.\n");
    PrintList(L);

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
