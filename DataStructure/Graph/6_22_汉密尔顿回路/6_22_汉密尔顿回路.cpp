// 6_22_汉密尔顿回路.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#define MAXN 201
using namespace std;

int main()
{
	int H[MAXN][MAXN];
	int N, M, K, V, W, Q, F;
	bool judge = true;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> V >> W;
		H[V][W] = 1; H[W][V] = 1;
	}
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		judge = true;
		cin >> Q;
		int* Visited = (int*)malloc(sizeof(int) * Q);
		if (Q - 1 != N) judge = false;//不可能正好覆盖全部顶点
		cin >> F;//首元
		Visited[F] = 1;
		V = F;
		for (int j = 1; j < Q - 1; j++) 
		{
			cin >> W;
			if (judge)
				if (H[V][W] != 1 || Visited[W] == 1) judge = false;//不连通或已访问过
			Visited[W] = 1;
			V = W;
		}
		cin >> W;//判别最后一个点
		if (judge && (W == F) && (H[V][W] == 1)) cout << "YES" << endl;
		else cout << "NO" << endl;
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
