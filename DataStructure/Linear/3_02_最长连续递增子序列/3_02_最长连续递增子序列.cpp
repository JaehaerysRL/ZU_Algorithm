// 3_02_最长连续递增子序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//给定一个顺序存储的线性表，请设计一个算法查找该线性表中最长的连续递增子序列。例如，(1,9,2,5,7,3,4,6,8,0)中最长的递增子序列为(3,4,6,8)。

//输入格式:
//输入第1行给出正整数n（≤10^5）；第2行给出n个整数，其间以空格分隔。
//输出格式 :
//在一行中输出第一次出现的最长连续递增子序列，数字之间用空格分隔，序列结尾不能有多余空格。

//输入样例：
//15
//1 9 2 5 7 3 4 6 8 0 11 15 17 17 10

//输出样例：
//3 4 6 8

#include <iostream>

using namespace std;

#define MAXSIZE 100000
typedef int ElementType;
typedef int Position;
typedef struct LNode* List;
struct LNode
{
	ElementType Data[MAXSIZE];
	Position Last;
};

List ReadInput() {
	List L;
	int n;
	L = (List)malloc(sizeof(struct LNode));
	cin >> n;
	for (L->Last = 0; L->Last < n; L->Last++)
	{
		cin >> L->Data[L->Last];
	}
	L->Last--;
	return L;
}

void PrintResult(List L, Position Left, Position Right) {
	cout << L->Data[Left];
	for (Position i = Left + 1; i <= Right; i++)
	{
		cout <<" "<< L->Data[i];
	}
}


int main()
{
	List L;
	Position Left, Right, tL, tR;
	int maxLen, tLen;

	L = ReadInput();
	Left = Right = tL = tR = 0;
	maxLen = tLen = 1;

	for (Position i = 1; i <= L->Last; i++)
	{
		if (L->Data[i] > L->Data[i - 1]) {
			tLen++;
			tR++;
		}
		else {
			if (tLen > maxLen) {
				maxLen = tLen;
				Left = tL;
				Right = tR;
			}
			tLen = 1;
			tL = tR = i;
		}
	}
	if (tLen > maxLen) {
		maxLen = tLen;
		Left = tL;
		Right = tR;
	}
	PrintResult(L, Left, Right);
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
