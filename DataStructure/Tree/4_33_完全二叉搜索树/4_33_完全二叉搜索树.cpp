// 4_33_完全二叉搜索树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <math.h>
#define MAXN 1000
using namespace std;

void createTree(int* tree, int* num, int blank, int left, int right) {
	if (left == right) {
		tree[blank] = num[left];
		return;
	}
	else {
		int k = 1;
		int root;
		int N = right - left + 1;
		while (pow(2, k) - 1 < N)
			k++;
		if (N <= pow(2, k) - pow(2, k - 2) - 1)//没有右子树
			root = right - pow(2, k - 2) + 1;
		else root = left + pow(2, k - 1) - 1;
		tree[blank] = num[root];
		if (left <= root - 1) 
			createTree(tree, num, blank * 2, left, root - 1);
		if (root + 1 <= right)
			createTree(tree, num, blank * 2 + 1, root + 1, right);	
	}
}

int cmp(const void* a, const void* b) {
	return *(const int*)a - *(const int*)b;
}

int main()
{
	int N;
	cin >> N;
	int* num = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
		cin >> num[i];
	qsort(num, N, sizeof(int), cmp);
	int* tree = (int*)malloc(sizeof(int) * (N + 1));
	createTree(tree, num, 1, 0, N - 1);
	cout << tree[1];
	for (int i = 2; i <= N; i++)
		cout << " " << tree[i];
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
