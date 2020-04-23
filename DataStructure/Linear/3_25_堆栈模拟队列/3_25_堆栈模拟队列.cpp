// 3_25_堆栈模拟队列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//设已知有两个堆栈S1和S2，请用这两个堆栈模拟出一个队列Q。
//所谓用堆栈模拟队列，实际上就是通过调用堆栈的下列操作函数:
//int IsFull(Stack S)：判断堆栈S是否已满，返回1或0；
//int IsEmpty(Stack S)：判断堆栈S是否为空，返回1或0；
//void Push(Stack S, ElementType item)：将元素item压入堆栈S；
//ElementType Pop(Stack S)：删除并返回S的栈顶元素。
//实现队列的操作，即入队void AddQ(ElementType item)和出队ElementType DeleteQ()。

//输入格式 :
//输入首先给出两个正整数N1和N2，表示堆栈S1和S2的最大容量。随后给出一系列的队列操作：A  item表示将item入列（这里假设item为整型数字）；D表示出队操作；T表示输入结束。
//输出格式 :
//对输入中的每个D操作，输出相应出队的数字，或者错误信息ERROR:Empty。如果入队操作无法执行，也需要输出ERROR:Full。每个输出占1行。
//输入样例 :
//3 2
//A 1 A 2 A 3 A 4 A 5 D A 6 D A 7 D A 8 D D D D T

//输出样例 :
//ERROR:Full
//1
//ERROR : Full
//2
//3
//4
//7
//8
//ERROR : Empty

#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<int>s1;
	stack<int>s2;
	int N1, N2, num;
	char order;
	cin >> N1 >> N2;
	if (N1 > N2) {
		num = N1;
		N1 = N2;
		N2 = num;
	}
	while (true)
	{
		cin >> order;
		if (order == 'T')
			break;
		else if (order == 'A')
		{
			cin >> num;
			if (s1.size() == N1)
			{
				if (s2.size() == 0)
				{
					while (s1.size())
					{
						s2.push(s1.top());
						s1.pop();
					}
					s1.push(num);
				}
				else
				{
					cout << "ERROR:Full" << endl;
					continue;
				}
			}
			else
			{
				s1.push(num);
			}
		}
		else if (order == 'D')
		{
			if (s2.size() == 0)
			{
				if (s1.size() == 0)
				{
					cout << "ERROR:Empty" << endl;
					continue;
				}
				else
				{
					while (s1.size())
					{
						s2.push(s1.top());
						s1.pop();
					}
				}
			}
			cout << s2.top() << endl;
			s2.pop();
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
