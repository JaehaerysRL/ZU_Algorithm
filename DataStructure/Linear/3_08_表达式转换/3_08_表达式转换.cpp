// 3_08_表达式转换.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//算术表达式有前缀表示法、中缀表示法和后缀表示法等形式。日常使用的算术表达式是采用中缀表示法，即二元运算符位于两个运算数中间。请设计程序将中缀表达式转换为后缀表达式。

//输入格式:
//输入在一行中给出不含空格的中缀表达式，可包含 + 、 - 、 * 、\以及左右括号()，表达式不超过20个字符。
//输出格式 :
//在一行中输出转换后的后缀表达式，要求不同对象（运算数、运算符号）之间以空格分隔，但结尾不得有多余空格。

//输入样例 :
//2 + 3 * (7 - 4) + 8 / 4
//输出样例 :
//2 3 7 4 - *+8 4 / +

#include <iostream>
#include <string.h>
#define MAXSIZE 21
using namespace std;

//操作符堆栈
typedef char ElementType;
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
	S->Data = (ElementType*)malloc(sizeof(ElementType) * MaxSize);
	S->Top = -1;
	S->MaxSize = MaxSize;
	return S;
}
bool IsNotEmpty(Stack S) {
	return S->Top > -1;
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

int pre(char c) {
	switch (c)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	default:
		return 0;
	}
}

int main()
{
	char str[MAXSIZE];
	cin >> str;
	int len = strlen(str);
	int flag = 0;
	Stack S = CreatStack(MAXSIZE);
	int i = 0;
	while (str[i] == '(') {
		Push(S, str[0]);
		i++;
	}
	cout << str[i];
	while ((str[i + 1] >= 49 && str[i + 1] <= 57) || str[i + 1] == '.')
	{
		cout << str[++i];
	}
	for (++i; i < len; i++)
	{
		if (str[i] >= 49 && str[i] <= 57) {//数字直接出
			cout << " " << str[i];
			while ((str[i+1] >= 49 && str[i+1] <= 57) || str[i + 1] == '.')
			{
				cout << str[++i];
			}
			flag = 0;
		}
		else if (str[i] == '(') {//左括号压栈
			Push(S, str[i]);
			flag = 1;
		}
		else if (str[i] == ')') {//右括号出到对应左括号
			while (Peek(S) != '(')
			{
				cout << " " << Pop(S);
			}
			Pop(S);
			flag = 0;
		}
		else {//其他操作符
			if (flag == 1) {//括号内第一个数前有操作符
				if (str[i] == '-') {//负数
					cout << " " << str[i];
					while ((str[i + 1] >= 49 && str[i + 1] <= 57) || str[i + 1] == '.')
					{
						cout << str[++i];
					}
				}
			}
			else if (pre(str[i]) > pre(Peek(S))) {
				Push(S, str[i]);
			}
			else {
				while (pre(Peek(S)) >= pre(str[i]))
				{
					cout << " " << Pop(S);
				}
				Push(S, str[i]);
			}
			flag = 0;
		}
	}
	while (IsNotEmpty(S))
	{
		cout << " " << Pop(S);
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
