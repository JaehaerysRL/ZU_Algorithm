// 6_33_天梯地图.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
//Constant area
const int MAXN = 1000000;
const int MIN_INF = 0x80000000;
const int MAX_INF = 0x7fffffff;
//Variable area
int n, m;
int beg[505];
int to[505050];
int nex[505050];
int weight[505050];
int tisme[505050];
int e;
int st, ed;
bool vis[505];
int answ[505];
int anst[505];
int stepw[505];
int tarw[505];
int tart[505];
int answw[505];
int answwsize;
int anstt[505];
int ansttsize;

struct p {
	int val;
	int self;
	int step;
	bool operator <(const p& b)const {
		return val > b.val;
	}
};

priority_queue<p> q;
void init() {
	e = 0;
	memset(beg, -1, sizeof(beg));
	return;
}
//Function area

void add(int a, int b, int w, int t) {
	nex[++e] = beg[a];
	beg[a] = e;
	to[e] = b;
	weight[e] = w;
	tisme[e] = t;
}

void Dijkstraw(int start) {
	q.push({ 0,start,0 });
	memset(vis, 0, sizeof(vis));
	memset(answ, 0x3f3f3f3f, sizeof(answ));
	memset(tarw, -1, sizeof(tarw));
	memset(stepw, 0x3f3f3f3f, sizeof(stepw));
	answ[start] = 0;
	while (q.size()) {
		p now = q.top();
		if (now.self == ed)
			break;
		q.pop();
		if (vis[now.self])
			continue;
		vis[now.self] = true;
		for (int i = beg[now.self]; i != -1; i = nex[i]) {
			int nx = to[i];
			if (answ[nx] > now.val + weight[i]) {
				answ[nx] = now.val + weight[i];
				q.push({ now.val + weight[i],nx,now.step + 1 });
				stepw[nx] = now.step + 1;
				tarw[nx] = now.self;
			}
			if (answ[nx] == now.val + weight[i]) {
				if (stepw[nx] > now.step + 1) {
					q.push({ now.val + weight[i],nx,now.step + 1 });
					stepw[nx] = now.step + 1;
					tarw[nx] = now.self;
				}
			}
		}
	}
	answwsize = 0;
	for (int i = ed; i != st; i = tarw[i]) {
		answw[++answwsize] = i;
	}
	answw[++answwsize] = st;
}

void Dijkstrat(int start) {
	while (q.size())
		q.pop();
	q.push({ 0,start,0 });
	memset(vis, 0, sizeof(vis));
	memset(anst, 0x3f3f3f3f, sizeof(anst));
	memset(answ, 0x3f3f3f3f, sizeof(answ));
	memset(stepw, 0x3f3f3f3f, sizeof(stepw));
	memset(tart, -1, sizeof(tart));
	answ[start] = 0;
	while (q.size()) {
		p now = q.top();
		if (now.self == ed)
			break;
		q.pop();
		if (vis[now.self])
			continue;
		vis[now.self] = true;
		for (int i = beg[now.self]; i != -1; i = nex[i]) {
			int nx = to[i];
			if (anst[nx] > now.val + tisme[i]) {
				anst[nx] = now.val + tisme[i];
				answ[nx] = now.val + weight[i];
				q.push({ now.val + tisme[i],nx,now.step + 1 });
				stepw[nx] = now.step + 1;
				tart[nx] = now.self;
			}
			if (anst[nx] == now.val + tisme[i]) {
				if (answ[nx] > now.val + weight[i]) {
					q.push({ now.val + tisme[i],nx,now.step + 1 });
					tart[nx] = now.self;
					stepw[nx] = now.step + 1;
				}
				else if (answ[nx] == now.val + weight[i]) {
					if (stepw[nx] > now.step + 1) {
						q.push({ now.val + tisme[i],nx,now.step + 1 });
						stepw[nx] = now.step + 1;
						tart[nx] = now.self;
					}
				}
			}
		}
	}
	ansttsize = 0;
	for (int i = ed; i != st; i = tart[i]) {
		anstt[++ansttsize] = i;
	}
	anstt[++ansttsize] = st;
}
int main() {
	ios::sync_with_stdio(false);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	init();
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		if (c == 1) {
			add(a, b, d, e);
		}
		else {
			add(a, b, d, e);
			add(b, a, d, e);
		}
	}
	cin >> st >> ed;
	Dijkstraw(st);
	int answww = answ[ed];
	Dijkstrat(st);
	cout << "Time = " << anst[ed];
	bool flagttt = true;
	if (answwsize == ansttsize) {
		for (int i = 1; i <= answwsize; i++) {
			if (answw[i] != anstt[i]) {
				flagttt = false;
				break;
			}
		}
	}
	else {
		flagttt = false;
	}
	if (flagttt == true) {
		cout << "; Distance = " << answww;
		cout << ": ";
		for (int i = answwsize; i != 0; i--) {
			if (i != answwsize)
				cout << " => ";
			cout << answw[i];
		}
		cout << endl;
	}
	else {
		cout << ": ";
		for (int i = ansttsize; i != 0; i--) {
			if (i != ansttsize)
				cout << " => ";
			cout << anstt[i];
		}
		cout << endl;
		cout << "Distance = " << answww;
		cout << ": ";
		for (int i = answwsize; i != 0; i--) {
			if (i != answwsize)
				cout << " => ";
			cout << answw[i];
		}
		cout << endl;
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
