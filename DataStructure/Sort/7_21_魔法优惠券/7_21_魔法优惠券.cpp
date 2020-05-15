// 7_21_魔法优惠券.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	int N, M;
	scanf_s("%d", &N);
	int* C = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
		scanf_s("%d", &C[i]);
	scanf_s("%d", &M);
	int* P = (int*)malloc(sizeof(int) * M);
	for (int i = 0; i < M; i++)
		scanf_s("%d", &P[i]);
	sort(C, C + N);
	sort(P, P + M);
	int cl = 0, cr = N - 1, pl = 0, pr = M - 1;
	long sum = 0, u, d;
	while (cl <= cr && pl <= pr)
	{
		if (abs(C[cl]) > abs(C[cr])) {
			d = C[cl] * P[pl];
			u = C[cl] * P[pr];
			if (d > u && d > 0) {
				sum += d;
				cl++;
				pl++;
			}
			else if (d <= u && u > 0) {
				sum += u;
				cl++;
				pr--;
			}
			else
				cl++;
		}
		else {
			d = C[cr] * P[pl];
			u = C[cr] * P[pr];
			if (d > u && d > 0) {
				sum += d;
				cr--;
				pl++;
			}
			else if (d <= u && u > 0) {
				sum += u;
				cr--;
				pr--;
			}
			else
				cr--;
		}
	}
	cout << sum;
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
