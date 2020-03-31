// 1_08_BinarySearch.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 习题1.8 二分查找 (20分)
// L是用户传入的一个线性表，其中ElementType元素可以通过>、==、<进行比较，
// 并且题目保证传入的数据是递增有序的。函数BinarySearch要查找X在Data中的位置，
// 即数组下标（注意：元素从下标1开始存储）。找到则返回下标，否则返回一个特殊的失败标记NotFound。

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode* List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

// 主体
Position BinarySearch(List L, ElementType X) {
    ElementType Left, Right, Mid;
    Left = 1;
    Right = L->Last;
    while (Left <= Right)
    {
        Mid = (Left + Right) / 2;
        if (L->Data[Mid] > X) Right = Mid - 1;
        else if (L->Data[Mid] < X) Left = Mid + 1;
        else return Mid;
    }
    return NotFound;
}


List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch(List L, ElementType X);

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch(L, X);
    printf("%d\n", P);

    return 0;
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
