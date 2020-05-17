// 6_32_社交网络图中结点的重要性计算.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
int n, m, x, y, i, f[10001];
vector<int>v[10001];
set<int>s;
int find(int x)
{
	if (f[x] == x) return x;
	else return f[x] = find(f[x]);
}
void mer(int x, int y)
{
	int a = find(x), b = find(y);
	if (a != b) f[a] = b;
}
int bfs(int s)
{
	int i, vis[10001] = { 0 }, last = s, tail, level = 1, sum = 0;
	queue<int>q;
	q.push(s);
	vis[s] = 1;
	while (!q.empty())
	{
		s = q.front();
		q.pop();
		for (i = 0; i < v[s].size(); i++)
		{
			if (vis[v[s][i]] == 0)
			{
				vis[v[s][i]] = 1;
				q.push(v[s][i]);
				tail = v[s][i];
				sum = sum + level;
			}
		}
		if (last == s)
		{
			level++;
			last = tail;
		}
	}
	return sum;
}
int main()
{
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) f[i] = i;
	while (m--)
	{
		scanf("%d %d", &x, &y);
		mer(x, y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (i = 1; i <= n; i++) s.insert(find(i));
	scanf("%d", &x);
	while (x--)
	{
		scanf("%d", &y);
		if (s.size() > 1) printf("Cc(%d)=%.2f\n", y, 0);
		else printf("Cc(%d)=%.2f\n", y, 1.0 / ((double)bfs(y) / (double)(n - 1)));
	}
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
