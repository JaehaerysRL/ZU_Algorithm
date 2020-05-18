// 8_23_银行排队问题之单窗口夹塞版.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <map>
#include <vector>
#include <queue>
#define inf 0x3f3f3f3f
using namespace std;

typedef long long ll;
const int maxn = 1e4 + 10;
struct Peo {
	string name;
	int arrive;
	int timeNeed;
	int waitTime;
	bool vis;
} p[maxn];
map<string, int> mp;
vector<string> v[110];
queue<Peo> que;
int m, n, k;
int pre[maxn];

void init() {
	for (int i = 0; i < 110; i++)
		v[i].clear();
	while (!que.empty()) que.pop();
	for (int i = 0; i < maxn; i++) {//对每一个客户进行编号，后边并查集存朋友圈会用到
		pre[i] = i;
	}
}

int Find(int x) {
	return x == pre[x] ? x : pre[x] = Find(pre[x]);
}

void putIn() {
	string name;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {//输入朋友圈
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> name;
			v[i].push_back(name);
		}
	}
	for (int i = 0; i < m; i++) {//输入每一个客户的有关信息
		cin >> p[i].name >> p[i].arrive >> p[i].timeNeed;
		if (p[i].timeNeed > 60)
			p[i].timeNeed = 60;
		p[i].waitTime = 0;
		p[i].vis = false;
		mp[p[i].name] = i;
	}
	for (int i = 0; i < n; i++) {//对给出的朋友圈，用并查集储存
		int tx = Find(mp[v[i][0]]);
		for (int j = 1; j < v[i].size(); j++) {
			int ty = Find(mp[v[i][j]]);
			if (tx != ty)
				pre[ty] = tx;
		}
	}
}

void solve() {
	int endTime = p[0].arrive + p[0].timeNeed, curId = 0;//endTime是窗口当前业务结束的时间,curId是当前正在
	p[0].vis = true;                                 //处理业务的客户
	p[0].waitTime = 0;
	que.push(p[0]);
	while (1) {
		bool isFind = false;
		for (int i = 1; i < m; i++) {//处理加塞的人(即与当前所有与正在处理业务的客户在一个朋友圈的人)
			int tx = Find(i), ty = Find(curId);
			if (tx == ty && !p[i].vis && p[i].arrive <= endTime) {//这个客户必须没有访问过，而且是在他朋友结束前到来
				p[i].vis = true;
				que.push(p[i]);//压入答案队列
				p[i].waitTime = endTime - p[i].arrive;//更新这个客户的等待时间
				endTime = endTime + p[i].timeNeed;//更新窗口的当前业务的结束时间
				curId = i;//更新窗口当前客户的id
				isFind = true;//说明有加塞的客户出现
			}
		}
		if (!isFind) {//没有加塞的客户的话,就去处理其余的客户
			for (int i = 1; i < m; i++) {
				int tx = Find(i), ty = Find(curId);
				if (tx != ty && !p[i].vis) {
					p[i].vis = true;
					que.push(p[i]);
					if (p[i].arrive <= endTime) {//根据这个客户到达时间的不同分别更新客户的等待时间
						p[i].waitTime = endTime - p[i].arrive;//窗口的结束时间
						endTime = endTime + p[i].timeNeed;
						curId = i;
					}
					else {
						p[i].waitTime = 0;
						endTime = p[i].arrive + p[i].timeNeed;
						curId = i;
					}
					break;//这种不加塞的客户只要找到一个就可以了,然后进入下一个循环去处理与这个客户有关的加塞客户
				}
			}
		}
		if (que.size() == m)
			break;
	}
	while (!que.empty()) {
		cout << que.front().name << endl;
		que.pop();
	}
	double sum = 0;
	for (int i = 0; i < m; i++) {//遍历所有的客户,求等待时间的和,求平均值
		sum += p[i].waitTime;
	}
	printf("%.1f\n", sum / m);
	return;
}

int main() {
	init();
	putIn();
	solve();
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
