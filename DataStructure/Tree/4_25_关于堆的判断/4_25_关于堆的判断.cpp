// 4_25_关于堆的判断.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//将一系列给定数字顺序插入一个初始为空的小顶堆H[]。随后判断一系列相关命题是否为真。命题分下列几种：
//x is the root：x是根结点；
//xand y are siblings：x和y是兄弟结点；
//x is the parent of y：x是y的父结点；
//x is a child of y：x是y的一个子结点。
//输入格式：
//每组测试第1行包含2个正整数N（≤ 1000）和M（≤ 20），分别是插入元素的个数、以及需要判断的命题数。下一行给出区间[−10000, 10000]内的N个要被插入一个初始为空的小顶堆的整数。之后M行，每行给出一个命题。题目保证命题中的结点键值都是存在的。
//输出格式：
//对输入的每个命题，如果其为真，则在一行中输出T，否则输出F。

#include <iostream>
#include <string>
#define MAXN 1000
#define MAXL 32
using namespace std;

typedef int ElementType;
typedef struct HNode* Heap;
struct HNode {
	ElementType* Data;
	int Size;
	int Capacity;
};
typedef Heap MinHeap;
MinHeap CreateHeap(int MaxSize) {
	MinHeap H = (MinHeap)malloc(sizeof(struct HNode));
	H->Data = (ElementType*)malloc(sizeof(ElementType) * (MaxSize + 1));
	H->Size = 0;
	H->Capacity = MaxSize;
	H->Data[0] = -10001;//哨兵
	return H;
}
bool IsFull(MinHeap H) {
	return (H->Size == H->Capacity);
}
bool IsEmpty(MinHeap H) {
	return (H->Size == 0);
}
bool Insert(MinHeap H, ElementType X) {
	int i;
	if (IsFull(H)) {
		return false;
	}
	i = ++H->Size;
	for (; H->Data[i / 2] > X; i /= 2)
	{
		H->Data[i] = H->Data[i / 2];
	}
	H->Data[i] = X;
	return true;
}
ElementType DeleteMin(MinHeap H) {
	int Parent, Child;
	ElementType MinItem, X;
	if (IsEmpty(H)) {
		return -1;
	}
	MinItem = H->Data[1];
	X = H->Data[H->Size--];
	for (Parent = 1; Parent * 2 <= H->Size; Parent = Child)
	{
		Child = Parent * 2;
		if ((Child != H->Size) && (H->Data[Child] > H->Data[Child + 1]))
			Child++;
		if (X <= H->Data[Child])break;
		else
			H->Data[Parent] = H->Data[Child];
	}
	H->Data[Parent] = X;
	return MinItem;
}
void PercDown(MinHeap H, int p) {
	int Parent, Child;
	ElementType X;
	X = H->Data[p];
	for (Parent = p; Parent * 2 < H->Size; Parent = Child)
	{
		Child = Parent * 2;
		if ((Child != H->Size) && (H->Data[Child] > H->Data[Child + 1]))
			Child++;
		if (X <= H->Data[Child])break;
		else
			H->Data[Parent] = H->Data[Child];
	}
	H->Data[Parent] = X;
}
void BuildHeap(MinHeap H) {
	int i;
	for (i = H->Size / 2; i > 0; i--)
	{
		PercDown(H, i);
	}
}

bool judgeRoot(MinHeap H, int x) {
	int r = H->Data[1];
	return (r == x);
}
bool judgeSiblings(MinHeap H, int x, int y) {
	int p = 1, q = 1;
	for (int i = 2; i <= H->Size; i++)
	{
		if (H->Data[i] == x) p = i;
		if (H->Data[i] == y) q = i;
	}
	return (p / 2 == q / 2);
}
bool judgeParent(MinHeap H, int x, int y) {
	int p = 1, q = 1;
	for (int i = 2; i <= H->Size; i++)
	{
		if (H->Data[i] == x) p = i;
		if (H->Data[i] == y) q = i;
	}
	return (p == q / 2);
}
bool judgeChild(MinHeap H, int x, int y) {
	int p = 1, q = 1;
	for (int i = 2; i <= H->Size; i++)
	{
		if (H->Data[i] == x) p = i;
		if (H->Data[i] == y) q = i;
	}
	return (p / 2 == q);
}

bool judge(MinHeap H) {
	int x, y;
	string s1, s2, s3, s4;
	cin >> x >> s1;
	if (s1[0] == 'a') {
		cin >> y >> s2 >> s3;
		return judgeSiblings(H, x, y);
	}
	cin >> s2 >> s3;
	if (s3[0] == 'r') {
		return judgeRoot(H, x);
	}
	else if (s3[0] == 'p') {
		cin >> s4 >> y;
		return judgeParent(H, x, y);
	}
	else {
		cin >> s4 >> y;
		return judgeChild(H, x, y);
	}
}

int main()
{
	int M, N, X;
	cin >> N >> M;
	MinHeap H = CreateHeap(N);
	for (int i = 0; i < N; i++)
	{
		cin >> X;
		Insert(H, X);
	}
	for (int i = 0; i < M; i++)
	{
		if (judge(H)) cout << "T" << endl;
		else cout << "F" << endl;
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
