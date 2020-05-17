// 8_12_直捣黄龙.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>  
#include <cstring>  
#include <algorithm>  
#include <queue>  
#include <map>  
#include <vector>  
#define MAXN 201
#define INF 65535
using namespace std;

map<int, string> ItoS;
map<string, int> StoI;
vector<int> q;
int n, m, s = 0, e, a[MAXN][MAXN], vis[MAXN] = { 0 }, pre[MAXN], d[MAXN], ren[MAXN], r[MAXN], num[MAXN], nu[MAXN] = { 0 };
void djs()
{
	ren[0] = 0;
	vis[0] = 1;
	nu[0] = 1;
	num[0] = 1;
	d[0] = 0;
	r[0] = 0;
	for (int j = 1; j < n; j++)
	{

		int g, min = INF;
		for (int i = 0; i < n; i++)
		{

			if (vis[i] == 0 && a[s][i] != INF)
			{

				if (a[s][i] + d[s] < d[i])
				{
					nu[i] = nu[s] + 1;
					d[i] = a[s][i] + d[s];
					num[i] = num[s];
					pre[i] = s;
					r[i] = r[s] + ren[i];
				}
				else if (a[s][i] + d[s] == d[i])
				{

					num[i] += num[s];
					if (nu[s] + 1 > nu[i])
					{

						nu[i] = nu[s] + 1;
						pre[i] = s;
						r[i] = r[s] + ren[i];
					}
					else if (nu[s] + 1 == nu[i])
					{
						if (r[s] + ren[i] > r[i])
						{
							r[i] = r[s] + ren[i];
							pre[i] = s;

						}
					}
				}
			}

		}
		for (int i = 0; i < n; i++)
		{
			if (vis[i] == 0 && d[i] < min)
			{
				min = d[i];
				g = i;
			}
		}
		s = g;
		vis[g] = 1;

	}
}

void dfs(int end)
{
	if (end == 0)
		return;
	q.push_back(pre[end]);
	dfs(pre[end]);
}
int main()
{
	string str1, str2, s1, e1;
	cin >> n >> m >> s1 >> e1;
	for (int i = 0; i <= 200; i++)
	{
		d[i] = INF;
		for (int j = 0; j <= 200; j++)
		{
			a[i][j] = INF;
		}
	}
	int t;
	ItoS[0] = s1;
	StoI[s1] = 0;
	for (int i = 1; i < n; i++)
	{
		cin >> str1 >> t;
		StoI[str1] = i;
		ItoS[i] = str1;
		ren[StoI[str1]] = t;
	}

	for (int i = 1; i <= m; i++)
	{
		cin >> str1 >> str2 >> t;
		a[StoI[str1]][StoI[str2]] = a[StoI[str2]][StoI[str1]] = t;

	}
	e = StoI[e1];
	djs();
	dfs(e);
	for (int i = q.size() - 1; i >= 0; i--)
	{
		cout << ItoS[q[i]] << "->";
	}
	cout << ItoS[e] << endl;
	cout << num[e] << ' ' << d[e] << ' ' << r[e];
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
