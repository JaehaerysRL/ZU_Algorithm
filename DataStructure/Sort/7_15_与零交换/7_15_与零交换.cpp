// 7_15_与零交换.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

int main()
{
	int N, S = 0, K = 0, p = 0, q;
	scanf_s("%d", &N);
	int* num = (int*)malloc(sizeof(int) * N);
	int* judge = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &num[i]);
		judge[i] = 1;
	}
	while (p < N)
	{
		int c = 0, i, q = p;
		while (judge[p]) {
			judge[p] = 0;
			p = num[p];
			c++;
		}
		if (c > 1) K++;
		else S++;
		for (i = q; i < N; i++)
			if (judge[i]) break;
		p = i;
	}
	if (num[0] == 0) printf("%d\n", N - S + K);
	else printf("%d\n", N - S + K - 2);
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
