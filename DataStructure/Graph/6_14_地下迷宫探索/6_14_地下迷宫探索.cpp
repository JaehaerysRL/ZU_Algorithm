// 6_14_地下迷宫探索.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 1001
using namespace std;

vector<int> node[MAXN];
int visited[MAXN];
int cnt = 0;
int flag = 0;

void DFS(int S) {
	cnt++;
	if (flag)
		printf(" %d", S);
	else {
		printf("%d", S);
		flag = 1;
	}
	visited[S] = 1;
	for (int i = 0; i < node[S].size(); i++) 
	{
		int next = node[S][i];
		int sig = 0;
		if (!visited[next]) {
			sig = 1;
			DFS(next);
		}
		if (sig)
			printf(" %d", S);
	}
}

int main()
{
	int N, M, S, P, Q;
	scanf_s("%d %d %d", &N, &M, &S);
	for (int i = 0; i < M; i++)
	{
		scanf_s("%d %d", &P, &Q);
		node[P].push_back(Q);
		node[Q].push_back(P);
	}
	for (int i = 1; i <= N; i++)
		sort(node[i].begin(), node[i].end());
	DFS(S);
	if (cnt != N) cout << " 0" << endl;
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
