// 4_23_二叉树的非递归遍历.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//本题要求用非递归的方法实现对给定二叉树的 3 种遍历。
#include <iostream>

typedef char ElementType;
typedef struct TNode* Position;
typedef Position BinTree;
struct TNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
	int flag;
};

/*------堆栈的定义-------*/
typedef Position SElementType;
typedef struct SNode* PtrToSNode;
struct SNode {
	SElementType Data;
	PtrToSNode Next;
};
typedef PtrToSNode Stack;

/* 裁判实现，细节不表 */
Stack CreateStack();
bool IsEmpty(Stack S);
bool Push(Stack S, SElementType X);
SElementType Pop(Stack S); /* 删除并仅返回S的栈顶元素 */
SElementType Peek(Stack S);/* 仅返回S的栈顶元素 */
/*----堆栈的定义结束-----*/

BinTree CreateBinTree(); /* 裁判实现，细节不表 */
void InorderTraversal(BinTree BT);
void PreorderTraversal(BinTree BT);
void PostorderTraversal(BinTree BT);

int main()
{
	BinTree BT = CreateBinTree();
	printf("Inorder:");    InorderTraversal(BT);    printf("\n");
	printf("Preorder:");   PreorderTraversal(BT);   printf("\n");
	printf("Postorder:");  PostorderTraversal(BT);  printf("\n");
	return 0;
}
/* 你的代码将被嵌在这里 */
void InorderTraversal(BinTree BT) {
	BinTree T;
	Stack S = CreateStack();
	T = BT;
	while (T || !IsEmpty(S))
	{
		while (T)
		{
			Push(S, T);
			T = T->Left;
		}
		T = Pop(S);
		printf(" %c", T->Data);
		T = T->Right;
	}
}
void PreorderTraversal(BinTree BT) {
	BinTree T;
	Stack S = CreateStack();
	T = BT;
	while (T || !IsEmpty(S))
	{
		while (T)
		{
			printf(" %c", T->Data);
			Push(S, T);
			T = T->Left;
		}
		T = Pop(S);
		T = T->Right;
	}
}
void PostorderTraversal(BinTree BT) {
	BinTree T;
	Stack S = CreateStack();
	T = BT;
	while (T || !IsEmpty(S))
	{
		while (T)
		{
			Push(S, T);
			T = T->Left;
		}
		T = Peek(S);
		if (T->flag != 1) {
			T->flag = 1;
			T = T->Right;
		}
		else {
			T = Pop(S);
			printf(" %c", T->Data);
			T = NULL;
		}
	}
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
