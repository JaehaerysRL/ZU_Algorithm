// 4_14_堆中的路径.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#define MINDATA -10001

using namespace std;
typedef int ElementType;
typedef struct HNode* Heap;
struct HNode {
	ElementType* Data;
	int Size;
	int Capacity;
};
typedef Heap MinHeap;

MinHeap CreateHeap(int MaxSize);
bool Insert(MinHeap H, ElementType X);

int main()
{
	int N, M;
	ElementType X;
	MinHeap H;
	cin >> N >> M;
	H = CreateHeap(N);
	for (int i = 0; i < N; i++)
	{
		cin >> X;
		Insert(H, X);
	}
	for (int j = 0; j < M; j++)
	{
		cin >> X;
		cout << H->Data[X];
		for (X /= 2; X > 0; X /= 2)
		{
			cout << " " << H->Data[X];
		}
		cout << endl;
	}
}

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

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
