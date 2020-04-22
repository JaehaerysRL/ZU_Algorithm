// 3_01_线性表元素的区间删除.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//给定一个顺序存储的线性表，请设计一个函数删除所有值大于min而且小于max的元素。删除后表中剩余元素保持顺序存储，并且相对位置不能改变。

#include <iostream>
#include <stdio.h>

#define MAXSIZE 20
typedef int ElementType;

typedef int Position;
typedef struct LNode* List;
struct LNode {
	ElementType Data[MAXSIZE];
	Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标0开始存储 */
void PrintList(List L); /* 裁判实现，细节不表 */
List Delete(List L, ElementType minD, ElementType maxD);

int main()
{
	List L;
	ElementType minD, maxD;
	int i;

	L = ReadInput();
	scanf("%d %d", &minD, &maxD);
	L = Delete(L, minD, maxD);
	PrintList(L);

	return 0;
}

/* 你的代码将被嵌在这里 */
List Delete(List L, ElementType minD, ElementType maxD) {
	int i, p;
	for (i = 0; i <= L->Last; i++)
	{
		if (L->Data[i] > minD && L->Data[i] < maxD) break;
	}
	p = i;
	for (; i <= L->Last; i++)
	{
		if (!(L->Data[i] > minD && L->Data[i] < maxD)) L->Data[p++] = L->Data[i];
	}
	L->Last = p - 1;
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
