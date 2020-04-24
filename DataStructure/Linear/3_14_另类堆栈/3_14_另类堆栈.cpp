// 3_14_另类堆栈.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//在栈的顺序存储实现中，另有一种方法是将Top定义为栈顶的上一个位置。请编写程序实现这种定义下堆栈的入栈、出栈操作。
//如果堆栈已满，Push函数必须输出“Stack Full”并且返回false；如果队列是空的，则Pop函数必须输出“Stack Empty”，并且返回ERROR。

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
typedef int ElementType;
typedef enum { push, pop, end } Operation;
typedef int Position;
typedef struct SNode* PtrToSNode;
struct SNode {
	ElementType* Data;  /* 存储元素的数组 */
	Position Top;       /* 栈顶指针       */
	int MaxSize;        /* 堆栈最大容量   */
};
typedef PtrToSNode Stack;

Stack CreateStack(int MaxSize)
{
	Stack S = (Stack)malloc(sizeof(struct SNode));
	S->Data = (ElementType*)malloc(MaxSize * sizeof(ElementType));
	S->Top = 0;
	S->MaxSize = MaxSize;
	return S;
}

bool Push(Stack S, ElementType X);
ElementType Pop(Stack S);

Operation GetOp();          /* 裁判实现，细节不表 */
void PrintStack(Stack S); /* 裁判实现，细节不表 */

int main()
{
	ElementType X;
	Stack S;
	int N, done = 0;

	scanf("%d", &N);
	S = CreateStack(N);
	while (!done) {
		switch (GetOp()) {
		case push:
			scanf("%d", &X);
			Push(S, X);
			break;
		case pop:
			X = Pop(S);
			if (X != ERROR) printf("%d is out\n", X);
			break;
		case end:
			PrintStack(S);
			done = 1;
			break;
		}
	}
	return 0;
}

/* 你的代码将被嵌在这里 */
bool Push(Stack S, ElementType X) {
	bool judge;
	if (S->Top == S->MaxSize) {
		judge = false;
		printf("Stack Full\n");
	}
	else {
		judge = true;
		S->Data[(S->Top)++] = X;
	}
	return judge;
}
ElementType Pop(Stack S) {
	ElementType X;
	if (S->Top == 0) {
		X = ERROR;
		printf("Stack Empty\n");
	}
	else {
		X = S->Data[--(S->Top)];
	}
	return X;
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
