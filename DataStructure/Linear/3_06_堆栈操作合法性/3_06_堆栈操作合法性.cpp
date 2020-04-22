// 3_06_堆栈操作合法性.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//假设以S和X分别表示入栈和出栈操作。如果根据一个仅由S和X构成的序列，对一个空堆栈进行操作，相应操作均可行（如没有出现删除时栈空）且最后状态也是栈空，则称该序列是合法的堆栈操作序列。请编写程序，输入S和X序列，判断该序列是否合法。

//输入格式:
//输入第一行给出两个正整数N和M，其中N是待测序列的个数，M（≤50）是堆栈的最大容量。随后N行，每行中给出一个仅由S和X构成的序列。序列保证不为空，且长度不超过100。
//输出格式 :
//对每个序列，在一行中输出YES如果该序列是合法的堆栈操作序列，或NO如果不是。

//输入样例：
//4 10
//SSSXXSXXSX
//SSSXXSXXS
//SSSSSSSSSSXSSXXXXXXXXXXX
//SSSXXSXXX

//输出样例：
//YES
//NO
//NO
//NO

#include <iostream>
#define MAXM 101

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

Stack CreatStack(int MaxSize) {
	Stack S = (Stack)malloc(sizeof(struct SNode));
	S->Data = (ElementType*)malloc(MaxSize * sizeof(ElementType));
	S->Top = -1;
	S->MaxSize = MaxSize;
	return S;
}
bool IsEmpty(Stack S) {
	return S->Top == -1;
}
bool IsFull(Stack S) {
	return S->Top == S->MaxSize - 1;
}
bool Push(Stack S, ElementType X) {
	if (IsFull(S)) return false;
	else {
		S->Data[++(S->Top)] = X;
		return true;
	}
}
bool Pop(Stack S) {
	if (IsEmpty(S)) return false;
	else {
		(S->Top)--;
		return true;
	}
}
void Clear(Stack S) {
	S->Top = -1;
}

int main()
{
	int N, M, i, j;
	cin >> N >> M;
	getchar();
	Stack S = CreatStack(M);
	for (i = 0; i < N; i++)
	{
		char str[MAXM];
		cin.getline(str, MAXM);
		Clear(S);
		for (j = 0; str[j] != '\0'; j++)
		{
			if ((str[j] == 'S') && (!Push(S, 1))) break;
			else if ((str[j] == 'X') && (!Pop(S))) break;
		}
		if (str[j] == '\0' && IsEmpty(S)) cout << "YES\n";
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
