// 3_05_符号配对.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//请编写程序检查C语言源程序中下列符号是否配对：/*与*/、(与)、[与]、{与}。

#include <iostream>
#define MAXN 100

using namespace std;
typedef struct SNode* Stack;
struct SNode
{
	char* Data;
	int Top;
	int MaxSize;
};

Stack CreateStack(int MaxSize) {
	Stack S = (Stack)malloc(sizeof(struct SNode));
	S->Data = (char*)malloc(MaxSize * sizeof(char));
	S->Top = -1;
	S->MaxSize = MaxSize;
	return S;
}
bool IsEmpty(Stack S) {
	return S->Top == -1;
}
void push(Stack S, char X) {
	S->Data[++(S->Top)] = X;
}
void pop(Stack S) {
	(S->Top)--;
}
int Peek(Stack S) {
	return S->Data[S->Top];
}

char fit(char c) {
	switch (c)
	{
	case '(':return ')';
	case '[':return ']';
	case '<':return '>';
	case '{':return '}';
	default:return NULL;
	}
}



int main()
{
	int judge = 0, k = 0;
	char c, tmp[MAXN], char1[MAXN];
	Stack S = CreateStack(MAXN);
	while (true)
	{
		char tmp[MAXN];
		cin.getline(tmp, MAXN);
		if (tmp[0] == '.' && tmp[1] == '\0') break;
		for (int i = 0; tmp[i] != '\0'; i++)
		{
			if (tmp[i] == '(' || tmp[i] == ')' || tmp[i] == '[' || tmp[i] == ']' || tmp[i] == '{' || tmp[i] == '}')
			{
				char1[k++] = tmp[i];
			}
			else if (tmp[i] == '/' && tmp[i + 1] == '*')
			{
				char1[k++] = '<';
				i++;
			}
			else if (tmp[i] == '*' && tmp[i + 1] == '/')
			{
				char1[k++] = '>';
				i++;
			}
		}
	}
	for (int i = 0; i < k; i++)
	{
		if (char1[i] == '(' || char1[i] == '[' || char1[i] == '{' || char1[i] == '<')
		{
			push(S, char1[i]);
		}
		else if (char1[i] == ')' || char1[i] == ']' || char1[i] == '}' || char1[i] == '>')
		{
			if (S->Top != -1 && fit(S->Data[S->Top]) == char1[i])
			{
				pop(S);
			}
			else if (S->Top = -1) {
				c = char1[i];
				judge = -1;
				break;
			}
			else {
				c = S->Data[S->Top];
				judge = 1;
				break;
			}
		}
	}
	if (judge == 0 && S->Top != -1) {
		c = S->Data[S->Top];
		judge = 1;
	}
	switch (judge)
	{
	case 0:
		cout << "YES\n";
		break;
	case 1:
		if(c!='<') cout << "NO\n" << c << "-?" << "\n";
		else cout << "NO\n" << "/*" << "-?" << "\n";
		break;
	case -1:
		if (c != '>') cout << "NO\n" << "?-" << c << "\n";
		else cout << "NO\n" << "?-" << "*/" << "\n";
		break;
	default:
		break;
	}
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
