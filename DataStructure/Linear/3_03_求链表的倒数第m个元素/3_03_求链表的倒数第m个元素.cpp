// 3_03_求链表的倒数第m个元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//请设计时间和空间上都尽可能高效的算法，在不改变链表的前提下，求链式存储的线性表的倒数第m（>0）个元素。

#include <stdio.h>
#include <stdlib.h>

#define ERROR -1

typedef int ElementType;
typedef struct Node* PtrToNode;
struct Node {
	ElementType Data;
	PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print(List L); /* 细节在此不表 */

ElementType Find(List L, int m);

int main()
{
	List L;
	int m;
	L = Read();
	scanf("%d", &m);
	printf("%d\n", Find(L, m));
	Print(L);
	return 0;
}

/* 你的代码将被嵌在这里 */
ElementType Find(List L, int m) {
	List p1, p2;
	p1 = p2 = L;
	int cnt = 0;
	while (p1 && ++cnt <= m) p1 = p1->Next;
	if (cnt <= m) return ERROR;
	while (p1)
	{
		p1 = p1->Next;
		p2 = p2->Next;
	}
	return p2->Data;
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
