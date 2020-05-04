// 4_27_修理牧场.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//农夫要修理牧场的一段栅栏，他测量了栅栏，发现需要N块木头，每块木头长度为整数Li个长度单位，于是他购买了一条很长的、能锯成N块的木头，即该木头的长度是Li的总和。
//但是农夫自己没有锯子，请人锯木的酬金跟这段木头的长度成正比。为简单起见，不妨就设酬金等于所锯木头的长度。例如，要将长度为20的木头锯成长度为8、7和5的三段，第一次锯木头花费20，将木头锯成12和8；第二次锯木头花费12，将长度为12的木头锯成7和5，总花费为32。如果第一次将木头锯成15和5，则第二次锯木头花费15，总花费为35（大于32）。
//请编写程序帮助农夫计算将木头锯成N块的最少花费。

//输入格式 :输入首先给出正整数N（≤10^4），表示要将木头锯成N块。第二行给出N个正整数（≤50），表示每段木块的长度。
//输出格式 :输出一个整数，即将木头锯成N块的最少花费。
//输入样例 :8 4 5 1 2 1 3 1 1
//输出样例 :	49

#include <iostream>
#define MAXN 10000
#define MINDATA 0
using namespace std;

typedef struct HTNode* HuffmanTree;
struct HTNode
{
	int Weight;
	HuffmanTree Left;
	HuffmanTree Right;
};
typedef HuffmanTree ElementType;
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
	H->Data[0] = (HuffmanTree)malloc(sizeof(struct HTNode));
	H->Data[0]->Left = H->Data[0]->Right = NULL;
	H->Data[0]->Weight = MINDATA;//哨兵
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
	for (; H->Data[i / 2]->Weight > X->Weight; i /= 2)
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
		return 0;
	}
	MinItem = H->Data[1];
	X = H->Data[H->Size--];
	for (Parent = 1; Parent * 2 <= H->Size; Parent = Child)
	{
		Child = Parent * 2;
		if ((Child != H->Size) && (H->Data[Child]->Weight > H->Data[Child + 1]->Weight))
			Child++;
		if (X->Weight <= H->Data[Child]->Weight)break;
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
		if ((Child != H->Size) && (H->Data[Child]->Weight > H->Data[Child + 1]->Weight))
			Child++;
		if (X->Weight <= H->Data[Child]->Weight)break;
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

HuffmanTree Huffman(MinHeap H) {
	int i, N;
	HuffmanTree T;
	BuildHeap(H);
	N = H->Size;
	for (i = 1; i < N; i++)
	{
		T = (HuffmanTree)malloc(sizeof(struct HTNode));
		T->Left = DeleteMin(H);
		T->Right = DeleteMin(H);
		T->Weight = T->Left->Weight + T->Right->Weight;
		Insert(H, T);
	}
	return DeleteMin(H);
}

typedef HuffmanTree SElementType;
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
void InorderTraversal(HuffmanTree BT,int N, int* sum) {
	HuffmanTree T;
	Stack S = CreateStack(N);
	T = BT;
	while (T || !IsEmpty(S))
	{
		while (T)
		{
			Push(S, T);
			T = T->Left;
		}
		T = Pop(S);
		if (T->Left || T->Right) *sum += T->Weight;
		T = T->Right;
	}
}

int main()
{
	int N, W;
	cin >> N;
	MinHeap H = CreateHeap(N);
	for (int i = 0; i < N; i++)
	{
		cin >> W;
		HuffmanTree X = (HuffmanTree)malloc(sizeof(struct HTNode));
		X->Left = X->Right = NULL;
		X->Weight = W;
		Insert(H, X);
	}
	HuffmanTree T = Huffman(H);
	int* sum = (int*)malloc(sizeof(int));
	*sum = 0;
	InorderTraversal(T, N, sum);
	cout << *sum;
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
