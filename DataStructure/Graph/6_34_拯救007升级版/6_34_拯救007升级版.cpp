// 6_34_拯救007升级版.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
#include <algorithm>
#include <cstdlib>
#include <memory.h>

using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1010;
struct node
{
	int x, y;
}a[maxn];
int n, d, pos, dmin = INF;
int dis[maxn][maxn], nex[maxn][maxn];//dis记录最短路径，nex记录从i到j的最短路路径节点
vector<int> ans;
stack<int> S;
void DFS(int x, int y)
{
	if (nex[x][y] == -1)
	{
		if (x != 0)//原点不参与输出
			S.push(x);
	}
	else if (nex[x][y] != INF)//由栈的特性从后往前放路径
	{
		DFS(nex[x][y], y);
		DFS(x, nex[x][y]);
	}
}
int main()
{
	cin >> n >> d;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].x >> a[i].y;
		if (min(50 - abs(a[i].x), 50 - abs(a[i].y)) <= d)
		{
			ans.push_back(i);
		}
	}
	a[0].x = a[0].y = 0;
	memset(dis, INF, sizeof(dis));
	memset(nex, INF, sizeof(nex));
	for (int i = 0; i <= n; i++)
	{
		dis[i][i] = 0;//注意
		for (int j = i + 1; j <= n; j++)
		{
			double x = 0;
			if (i == 0) x = 7.5;//池心岛半径
			double tx = a[i].x - a[j].x;
			double ty = a[i].y - a[j].y;
			double td = d + x;
			if (tx * tx + ty * ty <= td * td)//该步可走
			{
				dis[i][j] = dis[j][i] = 1;//dis标记为1
				nex[i][j] = nex[j][i] = -1;//nex标记为-1
			}
		}
	}

	for (int k = 0; k <= n; k++)
	{
		for (int i = 0; i <= n; i++)
		{
			if (dis[i][k] == INF) continue;
			for (int j = 0; j <= n; j++)
			{
				if (dis[k][j] == INF) continue;
				if (dis[i][j] > dis[i][k] + dis[k][j])
				{
					dis[i][j] = dis[j][i] = dis[i][k] + dis[k][j];
					nex[i][j] = nex[j][i] = k;//下一个节点,注意两边都要标记
				}
			}
		}
	}
	int num = INF;
	for (int i = 0; i < ans.size(); i++)//找最短路径（即最少要跳几步才能到达岸边）
		num = min(num, dis[0][ans[i]] + 1);//num+1才是最终值，因为还要跳到岸边
	if (num == INF)//没有找到路径
	{
		cout << "0" << endl;
		return 0;
	}
	if (d >= 50)//一步可跳到岸边
	{
		cout << "1" << endl;
		return 0;
	}
	for (int i = 0; i < ans.size(); i++)//找第一步最小的
	{
		if (num == dis[0][ans[i]] + 1)
		{
			DFS(0, ans[i]);
			int k = S.top();
			double tx = a[k].x;
			double ty = a[k].y;
			if (dmin > tx * tx + ty * ty)//更新最优值
			{
				pos = ans[i];
				dmin = tx * tx + ty * ty;
			}
			while (!S.empty()) S.pop();//置零，以备下次DFS
		}
	}

	S.push(pos);
	DFS(0, pos);
	cout << num << endl;
	while (!S.empty())
	{
		int k = S.top(); S.pop();
		cout << a[k].x << " " << a[k].y << endl;
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
