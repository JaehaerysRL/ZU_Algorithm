// 6_25_城市间紧急救援.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<stack>
#define INF 65535
#define MAXN 501
using namespace std;

int n, m, c1, c2;

int edge[MAXN][MAXN];     //存储各城市之间的联通关系
int weight[MAXN];        //存储各城市的救援队数目
int dist[MAXN];    //存储出发点到点i的最短路径的路径长度
int num[MAXN];     //表示从出发点到i结点最短路径的条数
int w[MAXN];         //表示从出发点到i点的救援队的数目和
int s[MAXN];        //存储已访问的点集
int path[MAXN];

void Dijkstra(int v)
{
	fill(dist, dist + 510, INF);
	dist[v] = 0;
	w[v] = weight[v];
	num[v] = 1;
	path[v] = -1;
	for (int i = 0; i < n; i++)
	{
		int u = -1, minx = INF;
		for (int j = 0; j < n; j++)
		{
			if (minx > dist[j] && s[j] == 0)   //在没加入到s集合中的点中寻找dist最小的点
			{
				u = j;
				minx = dist[j];
			}
		}
		if (u == -1) break;     //不连通终止
		s[u] = 1;             //将点u加入s集合
		for (int j = 0; j < n; j++)
		{
			if (s[j] == 0 && edge[u][j] != INF)
			{
				if (dist[u] + edge[u][j] < dist[j])
				{
					dist[j] = dist[u] + edge[u][j];
					num[j] = num[u];
					w[j] = w[u] + weight[j];
					path[j] = u;
				}
				else if (dist[u] + edge[u][j] == dist[j])
				{
					num[j] = num[j] + num[u];
					if (w[u] + weight[j] > w[j]) {
						w[j] = w[u] + weight[j];
						path[j] = u;
					}
				}
			}
		}
	}
}

int main()
{
	cin >> n >> m >> c1 >> c2;
	for (int i = 0; i < n; i++)
		cin >> weight[i];
	//edge初始化
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			edge[i][j] = INF;
	for (int i = 0; i < m; i++)
	{
		int a, b, l;
		cin >> a >> b >> l;
		edge[a][b] = edge[b][a] = l;
	}
	Dijkstra(c1);
	cout << num[c2] << " " << w[c2] << endl;
	//利用栈输出路径
	stack<int>ss;
	ss.push(c2);
	while (path[c2] != 0)
	{
		ss.push(path[c2]);
		c2 = path[c2];
	}
	cout << c1;
	while (!ss.empty())
	{
		cout << " " << ss.top();
		ss.pop();
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
