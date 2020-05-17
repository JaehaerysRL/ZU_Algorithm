// 8_13_逆散列问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>

using namespace std;
#define ll long long
#define MAXN 1001
int a[MAXN], b[MAXN];
int ans[MAXN];
int pos[MAXN], vis[MAXN];
int viss[MAXN];
int main()
{
	int n;
	scanf("%d", &n);
	int tot = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] >= 0)
			b[tot++] = a[i];
	}
	int tmp = 0, flag;
	sort(b, b + tot);
	for (int i = 0; i < tot; i++) {
		for (int j = 0; j < tot; j++) {
			if (vis[j])//当前的数已经用过了，就不需要再找了
				continue;
			flag = 1;
			for (int k = b[j] % n;;) {
				if (viss[k] == 0 && b[j] == a[k])
				{
					vis[j] = 1;
					viss[k] = 1;
					ans[i] = b[j];
					flag = 0;
					break;

				}
				if (viss[k] == 0)
					break;
				k++;
				if (k == n)
					k = 0;
			}
			if (!flag)
				break;
		}
	}
	for (int i = 0; i < tot; i++) {
		if (i == 0)
			printf("%d", ans[i]);
		else
			printf(" %d", ans[i]);

	}
	printf("\n");
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
