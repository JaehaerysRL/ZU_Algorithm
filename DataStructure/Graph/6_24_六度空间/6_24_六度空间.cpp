// 6_24_六度空间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#define MAXN 1001
using namespace std;

vector<int> G[MAXN];
int Visited[MAXN];
int N, M, Cnt;

void BFS(int i) 
{
	queue<int> Q;
	Q.push(i);
	Visited[i] = 1;
	Cnt++;
	for (int deep = 0; deep < 6; deep++) 
	{
		vector<int> v;
		while (Q.size() > 0) 
		{
			v.emplace_back(Q.front());
			Q.pop();
		}
		for (int j = 0; j < v.size(); j++)
		{
			for (int k = 0; k < G[v[j]].size(); k++)
			{
				int next = G[v[j]][k];
				if (Visited[next] == 0) 
				{
					Visited[next] = 1;
					Cnt++;
					Q.push(next);
				}
			}
		}
	}
}

int main()
{
	int W, V;
	double q;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &W, &V);
		G[W].emplace_back(V);
		G[V].emplace_back(W);
	}
	for (int i = 1; i <= N; i++) 
	{
		Cnt = 0;
		memset(Visited, 0, sizeof(Visited));
		BFS(i);
		q = Cnt * 1.0 / (double)N;
		printf("%d: %.2f%%\n", i, q * 100);
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
