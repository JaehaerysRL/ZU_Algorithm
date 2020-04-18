// 2_32_用扑克牌计算24点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//进阶实验2-3.2 用扑克牌计算24点 (25分)
//一副扑克牌的每张牌表示一个数（J、Q、K 分别表示 11、12、13，两个司令都表示 6）。任取4 张牌，即得到 4 个 1~13 的数，请添加运算符（规定为加 + 减 - 乘 * 除 / 四种）使之成为一个运算式。每个数只能参与一次运算，4 个数顺序可以任意组合，4 个运算符任意取 3 个且可以重复取。运算遵从一定优先级别，可加括号控制，最终使运算结果为 24。请输出一种解决方案的表达式，用括号表示运算优先。如果没有一种解决方案，则输出 - 1 表示无解。

//输入格式：
//输入在一行中给出 4 个整数，每个整数取值在[1, 13]。
//输出格式：
//输出任一种解决方案的表达式，用括号表示运算优先。如果没有解决方案，请输出 - 1。

//输入样例：
//2 3 12 12
//输出样例：
//((3 - 2) * 12) + 12

//穷举法

#include <iostream>

using namespace std;

double cu(double a, double b, char c) {
	switch (c)
	{
	case '+':return a + b;
	case '-':return a - b;
	case '*':return a * b;
	default:
		break;
	}
	if (b != 0) return a / b;
	else return 10000;
}

int main()
{
	double num[4]; 
	for (int i = 0; i < 4; i++)
	{
		cin >> num[i];
	}
	char baseC[4] = { '+', '-', '*', '/' };
	char opt[64][3];
	int count = 0, sig = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				opt[count][0] = baseC[i];
				opt[count][1] = baseC[j];
				opt[count][2] = baseC[k];
				count++;
			}
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (j != i) for (int k = 0; k < 4; k++)
			{
				if (k != i && k != j) for (int l = 0; l < 4; l++)
				{
					if (l != i && l != j && l != k) {
						for (int m = 0; m < 64; m++)
						{
							if (cu(cu(cu(num[i], num[j], opt[m][0]), num[k], opt[m][1]), num[l], opt[m][2]) == 24) {
								sig++;
								printf("((%d%c%d))%c%d)%c%d", (int)num[i], opt[m][0], (int)num[j], opt[m][1], (int)num[k], opt[m][2], (int)num[l]);
								goto END;
							}
							else if (cu(cu(num[i], num[j], opt[m][0]), cu(num[k], num[l], opt[m][2]), opt[m][1]) == 24){
								sig++;
								printf("(%d%c%d)%c(%d%c%d)", (int)num[i], opt[m][0], (int)num[j], opt[m][1], (int)num[k], opt[m][2], (int)num[l]);
								goto END;
							}
							else if (cu(cu(num[i], cu(num[j], num[k], opt[m][1]), opt[m][0]), num[l], opt[m][2]) == 24) {
								sig++;
								printf("(%d%c(%d%c%d))%c%d", (int)num[i], opt[m][0], (int)num[j], opt[m][1], (int)num[k], opt[m][2], (int)num[l]);
								goto END;
							}
							else if (cu(num[i], cu(cu(num[j], num[k], opt[m][1]), num[l], opt[m][2]), opt[m][0]) == 24) {
								sig++;
								printf("%d%c((%d%c%d)%c%d)", (int)num[i], opt[m][0], (int)num[j], opt[m][1], (int)num[k], opt[m][2], (int)num[l]);
								goto END;
							}
							else if (cu(num[i], cu(num[j], cu(num[k], num[l], opt[m][2]), opt[m][1]), opt[m][0]) == 24) {
								sig++;
								printf("%d%c(%d%c(%d%c%d))", (int)num[i], opt[m][0], (int)num[j], opt[m][1], (int)num[k], opt[m][2], (int)num[l]);
								goto END;
							}							
						}
					}
				}
			}
		}
	}
END:
	if (sig == 0)cout << -1;
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
