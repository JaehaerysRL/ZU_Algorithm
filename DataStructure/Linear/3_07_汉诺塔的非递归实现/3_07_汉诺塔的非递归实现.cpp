// 3_07_汉诺塔的非递归实现.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//借助堆栈以非递归（循环）方式求解汉诺塔的问题（n, a, b, c），即将N个盘子从起始柱（标记为“a”）通过借助柱（标记为“b”）移动到目标柱（标记为“c”），并保证每个移动符合汉诺塔问题的要求。

//输入格式:
//输入为一个正整数N，即起始柱上的盘数。
//输出格式 :
//每个操作（移动）占一行，按柱1->柱2的格式输出。

#include <iostream>
using namespace std;
//汉诺塔堆栈
typedef struct {
	int N;
	char A;
	char B;
	char C;
}Hanoi;
typedef int Position;
typedef struct SNode* Stack;
struct SNode
{
	Hanoi* Data;
	Position Top;
	int MaxSize;
};
Stack CreatStack(int MaxSize) {
	Stack S = (Stack)malloc(sizeof(struct SNode));
	S->Data = (Hanoi*)malloc(sizeof(Hanoi) * MaxSize);
	S->Top = -1;
	S->MaxSize = MaxSize;
	return S;
}
bool IsNotEmpty(Stack S) {
	return S->Top != -1;
}
void Push(Stack S, Hanoi H) {
	S->Data[++(S->Top)] = H;
}
Hanoi Pop(Stack S) {
	return S->Data[(S->Top)--];
}

int main()
{
	Stack S;
	Hanoi P, toPush;
	int N;
	cin >> N;
	S = CreatStack(N);
	P.N = N; P.A = 'a'; P.B = 'b'; P.C = 'c';
	Push(S, P);
	while (IsNotEmpty(S))
	{
		P = Pop(S);
		if (P.N = 1)
			cout << P.A << " -> " << P.C << "\n";
		else
		{
			toPush.N = P.N - 1;
			toPush.A = P.B; toPush.B = P.A; toPush.C = P.C;
			Push(S, toPush);
			toPush.N = 1;
			toPush.A = P.A; toPush.B = P.B; toPush.C = P.C;
			Push(S, toPush);
			toPush.N = P.N - 1;
			toPush.A = P.A; toPush.B = P.C; toPush.C = P.B;
			Push(S, toPush);
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
