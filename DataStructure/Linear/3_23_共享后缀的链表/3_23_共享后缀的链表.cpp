// 3_23_共享后缀的链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//有一种存储英文单词的方法，是把单词的所有字母串在一个单链表上。为了节省一点空间，如果有两个单词有同样的后缀，就让它们共享这个后缀。下图给出了单词“loading”和“being”的存储形式。本题要求你找出两个链表的公共后缀。

#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct Node* PtrToNode;
struct Node {
	ElementType Data; /* 存储结点数据 */
	PtrToNode   Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

void ReadInput(List L1, List L2); /* 裁判实现，细节不表 */
void PrintSublist(PtrToNode StartP); /* 裁判实现，细节不表 */
PtrToNode Suffix(List L1, List L2);

int main()
{
	List L1, L2;
	PtrToNode P;

	L1 = (List)malloc(sizeof(struct Node));
	L2 = (List)malloc(sizeof(struct Node));
	L1->Next = L2->Next = NULL;
	ReadInput(L1, L2);
	P = Suffix(L1, L2);
	PrintSublist(P);

	return 0;
}

/* 你的代码将被嵌在这里 */
PtrToNode Suffix(List L1, List L2) {
	List p, q, m, n, s;
	m = p = L1->Next;
	n = q = L2->Next;
	int len = 0;
	while (p && q)
	{
		p = p->Next;
		q = q->Next;
	}
	if (p) {
		while (p)
		{
			len++;
			p = p->Next;
		}
		for (int i = 0; i < len; i++) m = m->Next;
	}
	else if (q) {
		while (q)
		{
			len++;
			q = q->Next;
		}
		for (int i = 0; i < len; i++) n = n->Next;
	}
	s = m;
	while (m)
	{
		if (m->Data != n->Data) {
			s = m->Next;
		}
		m = m->Next;
		n = n->Next;
	}
	return s;
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
