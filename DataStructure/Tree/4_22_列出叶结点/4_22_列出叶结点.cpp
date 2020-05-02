// 4_22_列出叶结点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//对于给定的二叉树，本题要求你按从上到下、从左到右的顺序输出其所有叶节点。

//输入格式：
//首先第一行给出一个正整数 N（≤10），为树中结点总数。树中的结点从 0 到 N−1 编号。随后 N 行，每行给出一个对应结点左右孩子的编号。如果某个孩子不存在，则在对应位置给出 "-"。编号间以 1 个空格分隔。
//输出格式：
//在一行中按规定顺序输出叶节点的编号。编号间以 1 个空格分隔，行首尾不得有多余空格。

#include <iostream>
#define MAXN 10
using namespace std;

typedef struct TNode
{
	int Data;
	int Left;
	int Right;
}BinTree;

typedef BinTree QElementType;
typedef int QPosition;
typedef struct QNode* Queue;
struct QNode
{
	QElementType* Data;
	QPosition Front, Rear;
	int MaxSize;
};
QElementType QERROR;
Queue CreateQueue(int MaxSize) {
	Queue Q = (Queue)malloc(sizeof(struct QNode));
	Q->Data = (QElementType*)malloc(sizeof(QElementType)* MaxSize);
	Q->Front = Q->Rear = 0;
	Q->MaxSize = MaxSize;
	return Q;
}
bool IsFull(Queue Q) {
	return ((Q->Rear + 1) % Q->MaxSize == Q->Front);
}
bool IsEmpty(Queue Q) {
	return (Q->Rear == Q->Front);
}
bool AddQ(Queue Q, QElementType X) {
	if (IsFull(Q)) {
		return false;
	}
	else {
		Q->Rear = (Q->Rear + 1) % Q->MaxSize;
		Q->Data[Q->Rear] = X;
		return true;
	}
}
QElementType DeleteQ(Queue Q) {
	if (IsEmpty(Q)) {
		return QERROR;
	}
	else {
		Q->Front = (Q->Front + 1) % Q->MaxSize;
		return Q->Data[Q->Front];
	}
}

void LevelorderTraversal(BinTree BT[], int r) {
	BinTree T;
	Queue Q = CreateQueue(MAXN);
	if (r == -1) return;
	int lSig[MAXN + 1], i = 0;
	AddQ(Q, BT[r]);
	while (!IsEmpty(Q))
	{
		T = DeleteQ(Q);
		if ((T.Left == -1) && (T.Right == -1)) {
			lSig[i++] = T.Data;
		}
		if (T.Left != -1) AddQ(Q, BT[T.Left]);
		if (T.Right != -1) AddQ(Q, BT[T.Right]);
	}
	printf("%d", lSig[0]);
	for (int j = 1; j < i; j++)
	{
		printf(" %d", lSig[j]);
	}
}

int main()
{
	BinTree BT[MAXN];
	int N, r = -1, rSig[MAXN] = { 0 }, tmp;
	char tl, tr;
	scanf_s("%d", &N);
	getchar();
	for (int i = 0; i < N; i++)
	{
		scanf_s("%c %c", &tl, 1, &tr, 1);
		getchar();
		BT[i].Data = i;
		if (tl != 45) {
			tmp = tl - 48;
			BT[i].Left = tmp;
			rSig[tmp] = 1;
		}
		else BT[i].Left = -1;
		if (tr != 45) {
			tmp = tr - 48;
			BT[i].Right = tmp;
			rSig[tmp] = 1;
		}
		else BT[i].Right = -1;
	}
	for (int i = 0; i < N; i++)
	{
		if (rSig[i] == 0) r = i;
	}
	LevelorderTraversal(BT, r);
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
