// 6_23_拯救007.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <math.h>
#include <queue>
#define MAXN 101
using namespace std;

typedef struct _Position
{
	int x, y;
}Positon;
int N, D;
int DFSV[MAXN];
Positon P[MAXN];
queue<int> Q;
bool flag = false;


int sqDis(Positon a, Positon b) 
{
	return pow(a.x - b.x, 2) + pow(a.y - b.y, 2);
}
bool isSafe(Positon a) 
{
	return ((abs(a.x) + D >= 50) || (abs(a.y) + D >= 50));
}
void DFS(int i) 
{
	DFSV[i] = 1;
	if (isSafe(P[i])) 
	{
		flag = true;
		return;
	}
	for (int j = 0; j < N; j++)
		if (!DFSV[j] && sqDis(P[i], P[j]) <= D * D)
			DFS(j);
}

int main()
{
	cin >> N >> D;
	for (int i = 0; i < N; i++) 
	{
		cin >> P[i].x >> P[i].y;
		if (pow(P[i].x, 2) + pow(P[i].y, 2) <= pow(D + 15, 2)) Q.push(i);
	}
	while (!Q.empty())
	{
		DFS(Q.front());
		Q.pop();
	}
	if (flag) cout << "Yes" << endl;
	else cout << "No" << endl;
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
