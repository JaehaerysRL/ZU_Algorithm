// 3_22_单链表分段逆转.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//给定一个带头结点的单链表和一个整数K，要求你将链表中的每K个结点做一次逆转。例如给定单链表 1→2→3→4→5→6 和 K=3，你需要将链表改造成 3→2→1→6→5→4；如果 K=4，则应该得到 4→3→2→1→5→6。

//输入样例：
//6
//1 2 3 4 5 6
//4
//输出样例：
//4 3 2 1 5 6

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct Node* PtrToNode;
struct Node {
	ElementType Data; /* 存储结点数据 */
	PtrToNode   Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

List ReadInput(); /* 裁判实现，细节不表 */
void PrintList(List L); /* 裁判实现，细节不表 */
void K_Reverse(List L, int K);

int main()
{
	List L;
	int K;

	L = ReadInput();
	scanf("%d", &K);
	K_Reverse(L, K);
	PrintList(L);

	return 0;
}

/* 你的代码将被嵌在这里 */
void K_Reverse(List L, int K) {
	if (K > 1) {
		int cnt;
		List Left, Right, p, q, r;
		Left = L;
		Right = L->Next;
		int flag = 1;
		while (flag != 0)
		{
			for (cnt = 0; cnt < K; cnt++)
			{
				if (!Right) {
					flag = 0;
					break;
				}
				Right = Right->Next;
			}
			if (flag == 0)break;
			p = Left->Next; q = p->Next; r = q->Next;
			for (int i = 0; i < K - 2; i++)
			{
				q->Next = p;
				p = q;
				q = r;
				r = r->Next;
			}
			r = Left->Next;
			Left->Next = q;
			q->Next = p;
			Left = r;
			Left->Next = Right;
		}
	}
}




/* 你的代码将被嵌在这里 */


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
