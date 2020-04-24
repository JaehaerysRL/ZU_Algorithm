// 3_12_另类循环队列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//如果用一个循环数组表示队列，并且只设队列头指针Front，不设尾指针Rear，而是另设Count记录队列中元素个数。请编写算法实现队列的入队和出队操作。
//注意：如果队列已满，AddQ函数必须输出“Queue Full”并且返回false；如果队列是空的，则DeleteQ函数必须输出“Queue Empty”，并且返回ERROR。

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
typedef int ElementType;
typedef enum { addq, delq, end } Operation;
typedef int Position;
typedef struct QNode* PtrToQNode;
struct QNode {
	ElementType* Data;  /* 存储元素的数组   */
	Position Front;     /* 队列的头、尾指针 */
	int Count;          /* 队列中元素个数   */
	int MaxSize;        /* 队列最大容量     */
};
typedef PtrToQNode Queue;

Queue CreateQueue(int MaxSize)
{
	Queue Q = (Queue)malloc(sizeof(struct QNode));
	Q->Data = (ElementType*)malloc(MaxSize * sizeof(ElementType));
	Q->Front = 0;
	Q->Count = 0;
	Q->MaxSize = MaxSize;
	return Q;
}

bool AddQ(Queue Q, ElementType X);
ElementType DeleteQ(Queue Q);

Operation GetOp();  /* 裁判实现，细节不表 */

int main()
{
	ElementType X;
	Queue Q;
	int N, done = 0;

	scanf("%d", &N);
	Q = CreateQueue(N);
	while (!done) {
		switch (GetOp()) {
		case addq:
			scanf("%d", &X);
			AddQ(Q, X);
			break;
		case delq:
			X = DeleteQ(Q);
			if (X != ERROR) printf("%d is out\n", X);
			break;
		case end:
			while (Q->Count) printf("%d ", DeleteQ(Q));
			done = 1;
			break;
		}
	}
	return 0;
}

/* 你的代码将被嵌在这里 */
bool AddQ(Queue Q, ElementType X) {
	bool judge;
	if (Q->Count == Q->MaxSize) {
		printf("Queue Full\n");
		judge = false;
	}
	else {
		Q->Data[(Q->Front + Q->Count) % Q->MaxSize] = X;
		Q->Count++;
		judge = true;
	}
	return judge;
}
ElementType DeleteQ(Queue Q) {
	ElementType dq;
	if (Q->Count == 0) {
		printf("Queue Empty\n");
		dq = ERROR;
	}
	else {
		Q->Count--;
		dq = Q->Data[Q->Front];
		Q->Front = (Q->Front + 1) % Q->MaxSize;
	}
	return dq;
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
