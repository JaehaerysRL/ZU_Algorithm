// 4_12_平衡二叉树的根.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//将给定的一系列数字插入初始为空的AVL树，请你输出最后生成的AVL树的根结点的值。

//输入格式:
//输入的第一行给出一个正整数N（≤20），随后一行给出N个不同的整数，其间以空格分隔。
//输出格式 :
//在一行中输出顺序插入上述整数到一棵初始为空的AVL树后，该树的根结点的值。

//输入样例1 :
//5
//88 70 61 96 120
//输出样例1 :
//70

#include <iostream>
using namespace std;

typedef int ElementType;
typedef struct AVLNode* AVLPosition;
typedef AVLPosition AVLTree;
struct AVLNode {
	ElementType Data;
	AVLTree Left;
	AVLTree Right;
	int Height;
};

int Max(int a, int b) {
	return a > b ? a : b;
}
int GetHeight(AVLTree A) {
	if (A) return A->Height;
	else return 0;
}
AVLTree SingleLeftRotation(AVLTree A) {
	AVLTree B = A->Left;
	A->Left = B->Right;
	B->Right = A;
	A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
	B->Height = Max(GetHeight(B->Left), A->Height) + 1;
	return B;
}
AVLTree SingleRightRotation(AVLTree A) {
	AVLTree B = A->Right;
	A->Right = B->Left;
	B->Left = A;
	A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
	B->Height = Max(GetHeight(B->Right), A->Height) + 1;
	return B;
}
AVLTree DoubleLeftRightRotation(AVLTree A) {
	A->Left = SingleRightRotation(A->Left);
	return SingleLeftRotation(A);
}
AVLTree DoubleRightLeftRotation(AVLTree A) {
	A->Right = SingleLeftRotation(A->Right);
	return SingleRightRotation(A);
}
AVLTree Insert(AVLTree T, ElementType X) {
	if (!T) {
		T = (AVLTree)malloc(sizeof(struct AVLNode));
		T->Data = X;
		T->Height = 1;
		T->Left = T->Right = NULL;
	}
	else if (X < T->Data) {
		T->Left = Insert(T->Left, X);
		//如需左旋
		if (GetHeight(T->Left) - GetHeight(T->Right) == 2)
			if (X < T->Left->Data)
				T = SingleLeftRotation(T);
			else
				T = DoubleLeftRightRotation(T);
	}
	else if (X > T->Data) {
		T->Right = Insert(T->Right, X);
		//如需右旋
		if (GetHeight(T->Left) - GetHeight(T->Right) == -2)
			if (X > T->Right->Data)
				T = SingleRightRotation(T);
			else
				T = DoubleRightLeftRotation(T);
	}
	T->Height = Max(GetHeight(T->Left), GetHeight(T->Right)) + 1;
	return T;
}

int main()
{
	int N, X;
	AVLTree T;
	cin >> N;
	cin >> X;
	T = (AVLTree)malloc(sizeof(struct AVLNode));
	T->Data = X;
	T->Height = 1;
	T->Left = T->Right = NULL;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> X;
		T = Insert(T, X);
	}
	cout << T->Data;
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
