﻿// 2_01_简单计算器.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//模拟简单运算器的工作。假设计算器只能进行加减乘除运算，运算数和结果都是整数，四种运算符的优先级相同，按从左到右的顺序计算。

//输入格式:
//输入在一行中给出一个四则运算算式，没有空格，且至少有一个操作数。遇等号”=”说明输入结束。
//输出格式:
//在一行中输出算式的运算结果，或者如果除法分母为0或有非法运算符，则输出错误信息“ERROR”。

//输入样例:
//1+2*10-10/2=
//输出样例:
//10


#include <iostream>

int main()
{
	int sum = 0, temp;
	char opt = '+';
	char tempopt;
	while (opt != '=')
	{
		scanf("%d%c", &temp, &tempopt);
		if (opt == '+') sum += temp;
		else if (opt == '-') sum -= temp;
		else if (opt == '*') sum *= temp;
		else if (opt == '/') {
			if (temp == 0) goto ERROR;
			sum /= temp;
		}
		else goto ERROR;
		opt = tempopt;
	}
	printf("%d", sum);
	return 0;
ERROR:printf("ERROR");
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
