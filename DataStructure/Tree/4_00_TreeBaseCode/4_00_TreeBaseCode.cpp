// 4_00_TreeBaseCode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

#define MAXSIZE 100
#define NoInfo -1
#define MAXDATA 10000
#define MINDATA 10000
#define ERROR -1
//二叉树的链表结构
typedef int ElementType;
typedef struct TNode* Position;
typedef Position BinTree;
struct TNode
{
	ElementType Data;
	BinTree Left;
	BinTree Right;
};
//二叉树堆栈
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
	S->Data = (SElementType*)malloc(sizeof(SElementType));
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
		printf("堆栈满");
		return false;
	}
	else {
		S->Data[++(S->Top)] = X;
		return true;
	}
}
SElementType Pop(Stack S) {
	if (IsEmpty(S)) {
		printf("堆栈空");
		return SERROR;
	}
	else {
		return S->Data[(S->Top)--];
	}
}
//二叉树队列
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
	Q->Data = (QElementType*)malloc(sizeof(QElementType));
	Q->Front = Q->Rear = 0;
	Q->MaxSize = MaxSize;
}
bool IsFull(Queue Q) {
	return ((Q->Rear + 1) % Q->MaxSize == Q->Front);
}
bool IsEmpty(Queue Q) {
	return (Q->Rear == Q->Front);
}
bool AddQ(Queue Q, QElementType X) {
	if (IsFull(Q)) {
		printf("队列满");
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
		printf("队列空");
		return QERROR;
	}
	else {
		Q->Front = (Q->Front + 1) % Q->MaxSize;
		return Q->Data[Q->Front];
	}
}

//二叉树的操作
bool IsEmpty(BinTree BT);
void Traversal(BinTree BT);
BinTree CreatBinTree();
//递归遍历算法
//中序遍历
void InorderTraversal(BinTree BT) {
	if (BT) {
		InorderTraversal(BT->Left);
		printf("%d", BT->Data);
		InorderTraversal(BT->Right);
	}
}
//先序遍历
void PreorderTraversal(BinTree BT) {
	if (BT) {
		printf("%d", BT->Data);
		InorderTraversal(BT->Left);
		InorderTraversal(BT->Right);
	}
}
//后序遍历
void PostorderTraversal(BinTree BT) {
	if (BT) {
		InorderTraversal(BT->Left);
		InorderTraversal(BT->Right);
		printf("%d", BT->Data);
	}
}
//非递归中序遍历
void InorderTraversal(BinTree BT) {
	BinTree T;
	Stack S = CreateStack(MAXSIZE);
	T = BT;
	while (T || !IsEmpty(S))
	{
		while (T)
		{
			Push(S, T);
			T = T->Left;
		}
		T = Pop(S);
		printf("%d", T->Data);
		T = T->Right;
	}
}
//层序遍历
void LevelorderTraversal(BinTree BT) {
	BinTree T;
	Queue Q = CreateQueue(MAXSIZE);
	if (!BT) return;
	AddQ(Q, BT);
	while (!IsEmpty(Q))
	{
		T = DeleteQ(Q);
		printf("%d", T->Data);
		if (T->Left) AddQ(Q, T->Left);
		if (T->Right) AddQ(Q, T->Right);
	}
}
//求二叉树高度
int GetHeight(BinTree BT) {
	int HL, HR, MaxH;
	if (BT) {
		HL = GetHeight(BT->Left);
		HR = GetHeight(BT->Right);
		MaxH = HL > HR ? HL : HR;
		return MaxH + 1;
	}
	else return 0;
}
//层序生成二叉树
BinTree CreatBinTree() {
	ElementType Data;
	BinTree BT, T;
	Queue Q = CreateQueue(MAXSIZE);
	scanf("%d", &Data);
	if (Data != NoInfo) {
		BT = (BinTree)malloc(sizeof(struct TNode));
		BT->Data = Data;
		BT->Left = BT->Right = NULL;
		AddQ(Q, BT);
	}
	else return NULL;
	while (!IsEmpty(Q))
	{
		T = DeleteQ(Q);
		scanf("%d", &Data);
		if (Data == NoInfo) T->Left = NULL;
		else {
			T->Left = (BinTree)malloc(sizeof(struct TNode));
			T->Left->Data = Data;
			T->Left->Left = T->Left->Right = NULL;
			AddQ(Q, T->Left);
		}
		scanf("%d", &Data);
		if (Data == NoInfo) T->Right = NULL;
		else
		{
			T->Right = (BinTree)malloc(sizeof(struct TNode));
			T->Right->Data = Data;
			T->Right->Left = T->Right->Right = NULL;
			AddQ(Q, T->Right);
		}
	}
	return BT;
}

//二叉搜索树
//二叉搜索树的动态查找
Position Find(BinTree BST, ElementType X) {
	while (BST)
	{
		if (X > BST->Data)
			BST = BST->Right;
		else if (X < BST->Data)
			BST = BST->Left;
		else break;
	}
	return BST;
}
Position FindMin(BinTree BST) {
	if (BST)
		while (BST->Left)
			BST = BST->Left;
	return BST;
}
Position FindMax(BinTree BST) {
	if (BST)
		while (BST->Right)
			BST = BST->Right;
	return BST;
}
//二叉搜索树的插入
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
//二叉搜索树的删除
BinTree Delete(BinTree BST, ElementType X) {
	Position Tmp;
	if (!BST)
		printf("要删除的元素未找到");
	else {
		if (X < BST->Data)
			BST->Left = Delete(BST->Left, X);
		else if (X > BST->Data)
			BST->Right = Delete(BST->Right, X);
		else
		{
			if (BST->Left && BST->Right) {
				Tmp = FindMin(BST->Right);
				BST->Data = Tmp->Data;
				BST->Right = Delete(BST->Right, BST->Data);
			}
			else {
				Tmp = BST;
				if (BST->Left)
					BST = BST->Right;
				else
					BST = BST->Left;
				free(Tmp);
			}
		}
	}
	return BST;
}

//平衡二叉树
typedef struct AVLNode* AVLPosition;
typedef AVLPosition AVLTree;
struct AVLNode {
	ElementType Data;
	AVLTree Left;
	AVLTree Right;
	int Height;
};
//平衡二叉树操作
int Max(int a, int b) {
	return a > b ? a : b;
}
int GetHeight(AVLTree A) {
	return A->Height;
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
//树的应用
//堆及其操作
typedef struct HNode* Heap;
struct HNode {
	ElementType* Data;
	int Size;
	int Capacity;
};
typedef Heap MaxHeap;
typedef Heap MinHeap;
//最大堆的操作
MaxHeap CreateHeap(int MaxSize) {
	MaxHeap H = (MaxHeap)malloc(sizeof(struct HNode));
	H->Data = (ElementType*)malloc(sizeof(ElementType) * (MaxSize + 1));
	H->Size = 0;
	H->Capacity = MaxSize;
	H->Data[0] = MAXDATA;//哨兵
	return H;
}
bool IsFull(MaxHeap H) {
	return (H->Size == H->Capacity);
}
bool IsEmpty(MaxHeap H) {
	return (H->Size == 0);
}
bool Insert(MaxHeap H, ElementType X) {
	int i;
	if (IsFull(H)) {
		printf("最大堆已满");
		return false;
	}
	i = ++H->Size;
	for (; H->Data[i/2] < X; i /= 2)
	{
		H->Data[i] = H->Data[i / 2];
	}
	H->Data[i] = X;
	return true;
}
ElementType DeleteMax(MaxHeap H) {
	int Parent, Child;
	ElementType MaxItem, X;
	if (IsEmpty(H)) {
		printf("最大堆已空");
		return ERROR;
	}
	MaxItem = H->Data[1];
	X = H->Data[H->Size--];
	for (Parent = 1; Parent*2 <= H->Size; Parent = Child)
	{
		Child = Parent * 2;
		if ((Child != H->Size) && (H->Data[Child] < H->Data[Child + 1]))
			Child++;
		if (X >= H->Data[Child])break;
		else
			H->Data[Parent] = H->Data[Child];
	}
	H->Data[Parent] = X;
	return MaxItem;
}
void PercDown(MaxHeap H, int p) {
	int Parent, Child;
	ElementType X;
	X = H->Data[p];
	for (Parent = p; Parent*2 < H->Size; Parent = Child)
	{
		Child = Parent * 2;
		if ((Child != H->Size) && (H->Data[Child] < H->Data[Child + 1]))
			Child++;
		if (X >= H->Data[Child])break;
		else
			H->Data[Parent] = H->Data[Child];
	}
	H->Data[Parent] = X;
}
void BuildHeap(MaxHeap H) {
	int i;
	for (i = H->Size / 2; i > 0; i--)
	{
		PercDown(H, i);
	}
}
//最小堆的操作
MinHeap CreateHeap(int MaxSize) {
	MinHeap H = (MinHeap)malloc(sizeof(struct HNode));
	H->Data = (ElementType*)malloc(sizeof(ElementType) * (MaxSize + 1));
	H->Size = 0;
	H->Capacity = MaxSize;
	H->Data[0] = MINDATA;//哨兵
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
		printf("最小堆已满");
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
		printf("最小堆已空");
		return ERROR;
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
//哈夫曼树
typedef struct HTNode* HuffmanTree;
struct HTNode
{
	int Weight;
	HuffmanTree Left;
	HuffmanTree Right;
};

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
//集合及其运算
typedef int SetName;
typedef ElementType SetType[MAXSIZE];
//路径压缩
SetName Find(SetType S, ElementType X) {
	if (S[X] < 0)
		return X;
	else
		return S[X] = Find(S, S[X]);
}
//按秩合并
void Union(SetType S, SetName Root1, SetName Root2) {
	if (S[Root2] < S[Root1]) {
		S[Root2] += S[Root1];
		S[Root1] = Root2;
	}
	else {
		S[Root1] += S[Root2];
		S[Root2] = Root1;
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
