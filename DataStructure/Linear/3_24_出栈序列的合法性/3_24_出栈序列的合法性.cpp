// 3_24_出栈序列的合法性.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//给定一个最大容量为 M 的堆栈，将 N 个数字按 1, 2, 3, ..., N 的顺序入栈，允许按任何顺序出栈，则哪些数字序列是不可能得到的？例如给定 M=5、N=7，则我们有可能得到{ 1, 2, 3, 4, 5, 6, 7 }，但不可能得到{ 3, 2, 1, 7, 5, 6, 4 }。

//输入格式：
//输入第一行给出 3 个不超过 1000 的正整数：M（堆栈最大容量）、N（入栈元素个数）、K（待检查的出栈序列个数）。最后 K 行，每行给出 N 个数字的出栈序列。所有同行数字以空格间隔。
//输出格式：
//对每一行出栈序列，如果其的确是有可能得到的合法序列，就在一行中输出YES，否则输出NO。

//输入样例：
//5 7 5
//1 2 3 4 5 6 7
//3 2 1 7 5 6 4
//7 6 5 4 3 2 1
//5 6 4 3 7 2 1
//1 7 6 5 4 3 2
//输出样例：
//YES
//NO
//NO
//YES
//NO

#include <iostream>
using namespace std;

typedef int ElementType;
typedef int Position;
typedef struct SNode* Stack;
struct SNode
{
	ElementType* Data;
	Position Top;
	int MaxSize;
};
Stack CreateStack(int MaxSize) {
	Stack S = (Stack)malloc(sizeof(struct SNode));
	S->Data = (ElementType*)malloc(sizeof(ElementType) * MaxSize);
	S->Top = -1;
	S->MaxSize = MaxSize;
	return S;
}
bool IsNotEmpty(Stack S) {
	return S->Top > -1;
}
bool IsNotFool(Stack S) {
	return S->Top < (S->MaxSize - 1);
}
void Push(Stack S, ElementType X) {
	S->Data[++(S->Top)] = X;
}
ElementType Pop(Stack S) {
	return S->Data[(S->Top)--];
}
ElementType Peek(Stack S) {
	return S->Data[S->Top];
}
void Clear(Stack S) {
	S->Top = -1;
}

int main()
{
	int M, N, K;
	cin >> M >> N >> K;
	Stack S = CreateStack(M);
	for (int i = 0; i < K; i++)//检验序列
	{
		int flag = 1;
		Clear(S);
		int k = 1, tmp;
		Push(S, k++);
		for (int j = 0; j < N; j++)
		{
			cin >> tmp;
			if (flag == 1) {//只有还满足条件才检验
				if (Peek(S) == tmp) {//栈顶正好是检验值
					Pop(S);
				}
				else if (Peek(S) < tmp) {//需要继续压栈
					while (IsNotFool(S) && Peek(S) < tmp) {
						Push(S, k++);
					}
					if (Peek(S) == tmp) {
						Pop(S);
					}
					else {//堆栈满
						flag = 0;
					}
				}
				else {//需要多次出栈
					while (IsNotEmpty(S) && Peek(S) > tmp) {
						Pop(S);
					}
					if (Peek(S) == tmp) {
						Pop(S);
					}
					else {//堆栈提前空
						flag = 0;
					}
				}
			}
		}
		if (flag == 1) cout << "YES\n";
		else cout << "NO\n";
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
