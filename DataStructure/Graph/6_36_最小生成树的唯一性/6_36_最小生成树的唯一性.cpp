// 6_36_最小生成树的唯一性.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <memory.h>
#include <math.h>
#include <algorithm>
#include <cstdlib>
#define maxn 501
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
int N, M;
bool vis[maxn];              //求最小生成树的时候用来标记是不是已经走过
bool used[maxn][maxn];       //求次小生成树的时候用
int Map[maxn][maxn];         //储存任意两条边之间的关系
int dis[maxn];               //储存边的距离
int pre[maxn];               //储存之前的点
int MaxP[maxn][maxn];        //i 到 j 之间最大的距离
int f[maxn];                 //并查集求连通个数

int prim()                                    //prim算法求最小生成树
{
	for (int i = 1; i <= N; i++) {
		dis[i] = Map[i][1];
		pre[i] = 1;
	}
	dis[1] = 0;
	vis[1] = true;
	int ans = 0;

	for (int i = 1; i < N; i++) {
		int temp = INF, pos;
		for (int j = 1; j <= N; j++) {
			if (!vis[j] && temp > dis[j]) {
				temp = dis[j], pos = j;
			}
		}
		if (temp == INF)
			return -1;
		used[pre[pos]][pos] = used[pos][pre[pos]] = true;
		ans += dis[pos];
		vis[pos] = true;
		for (int j = 1; j <= N; j++) {
			if (vis[j] && j != pos)
				MaxP[pos][j] = MaxP[j][pos] = max(MaxP[j][pre[pos]], dis[pos]);
			if (!vis[j]) {
				if (dis[j] > Map[pos][j]) {
					dis[j] = Map[pos][j];
					pre[j] = pos;
				}
			}
		}
	}
	return ans;
}

void init()
{
	for (int i = 1; i <= N; i++)   //并查集的初始化
		f[i] = i;
	memset(Map, 0x3f, sizeof(Map));
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x3f, sizeof(dis));
	memset(MaxP, 0, sizeof(MaxP));
	return;
}
int Find(int x)
{
	if (x == f[x])
		return x;
	else
		return f[x] = Find(f[x]);
}
void unit(int a, int b)
{
	int fa = Find(a);
	int fb = Find(b);
	if (fa == fb)
		return;
	else {
		if (fa < fb) f[fb] = fa;
		else        f[fa] = fb;
	}
	return;
}
int main()
{
	scanf("%d %d", &N, &M);
	init();
	while (M--) {
		int v1, v2, w;
		scanf("%d %d %d", &v1, &v2, &w);
		unit(v1, v2);
		Map[v1][v2] = Map[v2][v1] = w;
	}
	int x = prim();
	if (x == -1) {              //如果不连通
		cout << "No MST" << endl;
		int sum = 0;
		for (int i = 1; i <= N; i++) {
			if (i == Find(i)) sum++;
		}
		cout << sum << endl;
	}
	else {
		cout << x << endl;
		int ans = INF;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i != j && !used[i][j])
					ans = min(ans, x + Map[i][j] - MaxP[i][j]);
			}
		}
		if (ans == x) cout << "No" << endl;
		else cout << "Yes" << endl;
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
