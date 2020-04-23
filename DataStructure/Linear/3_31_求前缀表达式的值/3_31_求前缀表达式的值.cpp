// 3_31_求前缀表达式的值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//算术表达式有前缀表示法、中缀表示法和后缀表示法等形式。前缀表达式指二元运算符位于两个运算数之前，例如2+3*(7-4)+8/4的前缀表达式是：+ + 2 * 3 - 7 4 / 8 4。请设计程序计算前缀表达式的结果值。

//输入格式:
//输入在一行内给出不超过30个字符的前缀表达式，只包含 + 、 - 、 * 、 / 以及运算数，不同对象（运算数、运算符号）之间以空格分隔。
//输出格式 :
//输出前缀表达式的运算结果，保留小数点后1位，或错误信息ERROR。

//输入样例 :
//++2 * 3 - 7 4 / 8 4
//输出样例 :
//13.0

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	stack<double> num;
	string inPut[100];
	int n = 0, flag = 1;
	while (cin >> inPut[n++]) {}
	for (int i = n - 2; i >= 0; i--)
	{
		if (inPut[i].length() == 1 && (inPut[i][0] == '+' || inPut[i][0] == '-' || inPut[i][0] == '*' || inPut[i][0] == '/')) {
			if (num.size() < 2) {
				flag = 0;
				break;
			}
			double a = num.top(); num.pop();
			double b = num.top(); num.pop();
			if (inPut[i][0] == '+') num.push(a + b);
			else if (inPut[i][0] == '-') num.push(a - b);
			else if (inPut[i][0] == '*') num.push(a * b);
			else {
				if (b == 0) {
					flag = 0;
					break;
				}
				else num.push(a / b);
			}
		}
		else {
			double x = atof(inPut[i].c_str());
			num.push(x);
		}
	}
	if (num.size() != 1) flag = 0;
	if (flag == 0) cout << "ERROR";
	else printf("%.1f", num.top());
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
