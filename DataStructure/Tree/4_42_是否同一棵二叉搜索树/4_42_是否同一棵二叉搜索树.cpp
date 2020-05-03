// 4_42_是否同一棵二叉搜索树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//给定一个插入序列就可以唯一确定一棵二叉搜索树。然而，一棵给定的二叉搜索树却可以由多种不同的插入序列得到。例如分别按照序列{2, 1, 3}和{2, 3, 1}插入初始为空的二叉搜索树，都得到一样的结果。于是对于输入的各种插入序列，你需要判断它们是否能生成一样的二叉搜索树。

//输入格式:
//输入包含若干组测试数据。每组数据的第1行给出两个正整数N(≤10)和L，分别是每个序列插入元素的个数和需要检查的序列个数。第2行给出N个以空格分隔的正整数，作为初始插入序列。最后L行，每行给出N个插入的元素，属于L个需要检查的序列。
//简单起见，我们保证每个插入序列都是1到N的一个排列。当读到N为0时，标志输入结束，这组数据不要处理。
//输出格式 :
//对每一组需要检查的序列，如果其生成的二叉搜索树跟对应的初始序列生成的一样，输出“Yes”，否则输出“No”。

//只要查找过程中有没见过的点就不同

#include <iostream>
#define MAXN 12

using namespace std;

typedef int ElementType;
typedef struct TNode* Position;
typedef Position BinTree;
struct TNode
{
	ElementType Data;
	BinTree Left;
	BinTree Right;
	int flag = 0;
};

typedef BinTree SElementType;
typedef int SPosition;
typedef struct SNode* Stack;
struct SNode
{
	SElementType* Data;
	SPosition Top;
	int MaxSize;
};
SElementType SERROR;
Stack CreateStack(int MaxSize) {
	Stack S = (Stack)malloc(sizeof(struct SNode));
	S->Data = (SElementType*)malloc(sizeof(SElementType) * (MaxSize + 1));
	S->Top = -1;
	S->MaxSize = MaxSize;
	return S;
}
bool IsFull(Stack S) {
	return (S->Top == S->MaxSize - 1);
}
bool IsEmpty(Stack S) {
	return (S->Top == -1);
}
bool Push(Stack S, SElementType X) {
	if (IsFull(S)) {
		return false;
	}
	else {
		S->Data[++(S->Top)] = X;
		return true;
	}
}
SElementType Pop(Stack S) {
	if (IsEmpty(S)) {
		return SERROR;
	}
	else {
		return S->Data[(S->Top)--];
	}
}
SElementType Peek(Stack S) {
	if (IsEmpty(S)) {
		return SERROR;
	}
	else {
		return S->Data[S->Top];
	}
}

BinTree Insert(BinTree BST, ElementType X) {
	if (!BST) {
		BST = (BinTree)malloc(sizeof(struct TNode));
		BST->Data = X;
		BST->Left = BST->Right = NULL;
	}
	else {
		if (X < BST->Data)
			BST->Left = Insert(BST->Left, X);
		else if (X > BST->Data)
			BST->Right = Insert(BST->Right, X);
	}
	return BST;
}

void ReSet(BinTree BST) {
	BinTree T;
	Stack S = CreateStack(MAXN);
	T = BST;
	while (T || !IsEmpty(S))
	{
		while (T)
		{
			Push(S, T);
			T = T->Left;
		}
		T = Pop(S);
		T->flag = 0;
		T = T->Right;
	}
}

bool Find(BinTree BST, ElementType X) {
	if (BST->flag == 1) {
		if (X < BST->Data)
			return Find(BST->Left, X);
		else if (X > BST->Data)
			return Find(BST->Right, X);
		else
			return false;
	}
	else {
		if (X == BST->Data) {
			BST->flag = 1;
			return true;
		}
		else return false;
	}
}

bool Check(BinTree BST, int N) {
	int num[MAXN];
	for (int i = 0; i < N; i++)
		cin >> num[i];
	for (int i = 0; i < N; i++)
		if (!Find(BST, num[i])) return false;
	return true;
}

int main()
{
	while (true)
	{
		int N, L, X;
		cin >> N;
		if (N == 0) break;
		cin >> L >> X;
		BinTree T = (BinTree)malloc(sizeof(struct TNode));
		T->Data = X;
		T->Left = T->Right = NULL;
		for (int i = 1; i < N; i++)
		{
			cin >> X;
			T = Insert(T, X);
		}
		for (int i = 0; i < L; i++)
		{
			ReSet(T);
			if (Check(T, N))cout << "Yes" << endl;
			else cout << "No" << endl;
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
