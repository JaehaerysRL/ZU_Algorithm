// 4_41_Tree_Traversals_Again.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//An inorder binary tree traversal can be implemented in a non-recursive way with a stack. For example, suppose that when a 6-node binary tree (with the keys numbered from 1 to 6) is traversed, the stack operations are: push(1); push(2); push(3); pop(); pop(); push(4); pop(); pop(); push(5); push(6); pop(); pop(). Then a unique binary tree (shown in Figure 1) can be generated from this sequence of operations. Your task is to give the postorder traversal sequence of this tree.
//Input Specification :
//Each input file contains one test case.For each case, the first line contains a positive integer N(≤30) which is the total number of nodes in a tree(and hence the nodes are numbered from 1 to N).Then 2N lines follow, each describes a stack operation in the format : "Push X" where X is the index of the node being pushed onto the stack; or "Pop" meaning to pop one node from the stack.
//Output Specification :
//For each test case, print the postorder traversal sequence of the corresponding tree in one line.A solution is guaranteed to exist.All the numbers must be separated by exactly one space, and there must be no extra space at the end of the line.

#include <iostream>
#include <string>

using namespace std;

typedef int ElementType;
typedef struct TNode* Position;
typedef Position BinTree;
struct TNode
{
	ElementType Data;
	BinTree Left;
	BinTree Right;
	int flag;
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

BinTree CreatBinTree(ElementType X) {
	BinTree T = (BinTree)malloc(sizeof(struct TNode));
	T->Data = X;
	T->Left = NULL;
	T->Right = NULL;
	T->flag = 0;
	return T;
}

void PostorderTraversal(BinTree BT, Stack S) {
	BinTree T = BT;
	int flag = 0;
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
			if (flag == 0) {
				printf("%d", T->Data);
				flag = 1;
			}
			else {
				printf(" %d", T->Data);
			}
			T = NULL;
		}
	}
}

BinTree Input(int N, Stack S) {
	int cnt = 0, X;
	BinTree BT, P, O;
	string opt0;
	cin >> opt0;
	cin >> X;
	BT = CreatBinTree(X);
	Push(S, BT);
	do
	{
		string opt;
		cin >> opt;
		if (opt[1] == 'u') {
			BinTree T;
			cin >> X;
			T = CreatBinTree(X);
			Push(S, T);
		}
		else {
			cnt++;
			O = Pop(S);
			if (!IsEmpty(S)) {
				P = Peek(S);
				if (!P->Left)
					P->Left = O;
				else {
					P = P->Left;
					while (P->Right)
						P = P->Right;
					P->Right = O;
				}
			}
			else {
				if (O->Data != BT->Data) {
					P = BT;
					while (P->Right)
						P = P->Right;
					P->Right = O;
				}
			}
		}
	} while (cnt < N);
	return BT;
}

int main()
{
	int N, cnt = 0;
	cin >> N;
	Stack S = CreateStack(N);

	BinTree BT = Input(N, S);
	
	PostorderTraversal(BT, S);
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
