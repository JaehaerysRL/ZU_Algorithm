// 8_22_银行排队问题之单队列多窗口加VIP服务.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn = 1000 + 5;
struct people {
	int T, P, VIP, counter_id;
}Customer[maxn];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d %d", &Customer[i].T, &Customer[i].P, &Customer[i].VIP);
		Customer[i].P = min(Customer[i].P, 60);
	}
	int K, vipK;
	scanf("%d %d", &K, &vipK);
	bool vis[maxn] = { 0 };
	queue<people> q;
	bool ok = true;

	for (int i = 0; i < n; ++i) {
		if (Customer[i].T > 0)
			break;
		if (Customer[i].VIP) {
			ok = false;
			Customer[i].counter_id = vipK;
			vis[i] = 1;
			q.push(Customer[i]);
			break;
		}
	}

	if (ok) {
		Customer[0].counter_id = 0;
		vis[0] = 1;
		q.push(Customer[0]);
	}

	int sum = 0, _max = 0, last = 0, now = 0;
	int windows[15] = { 0 }, num_windows[15] = { 0 };

	while (!q.empty()) {
		_max = max(_max, windows[q.front().counter_id] - q.front().T);
		sum += max(0, windows[q.front().counter_id] - q.front().T);
		windows[q.front().counter_id] = max(windows[q.front().counter_id], q.front().T) + q.front().P;
		last = max(last, windows[q.front().counter_id]);
		++num_windows[q.front().counter_id];

		int minn = INF, idx = 0;

		for (int i = 0; i < K; ++i) {
			if (windows[i] < minn) {
				minn = windows[i];
				idx = i;
			}
		}

		while (now < n && vis[now])
			++now;
		if (now == n)
			break;

		ok = true;

		if (Customer[now].T <= windows[idx]) {
			ok = true;
			if (idx == vipK || windows[idx] == windows[vipK]) {
				for (int i = now; i < n; ++i) {
					if (!vis[i]) {
						if (Customer[i].T > windows[idx]) {
							break;

						}
						if (Customer[i].VIP) {
							ok = false;
							Customer[i].counter_id = vipK;
							q.push(Customer[i]);
							vis[i] = 1;
							break;

						}
					}
				}
			}
			if (ok) {
				Customer[now].counter_id = idx;
				q.push(Customer[now]);
				vis[now] = 1;
			}
		}
		else {
			if (Customer[now].VIP && windows[vipK] <= Customer[now].T) {
				Customer[now].counter_id = vipK;
				q.push(Customer[now]);
				vis[now] = 1;
			}
			else {
				for (int i = 0; i < K; ++i) {
					if (windows[i] <= Customer[now].T) {
						Customer[now].counter_id = i;
						q.push(Customer[now]);
						vis[now] = 1;
						break;
					}
				}
			}
		}
		q.pop();
	}

	printf("%.1f %d %d\n", sum * 1.0 / n, _max, last);

	for (int i = 0; i < K; ++i) {
		printf("%d%c", num_windows[i], i == K - 1 ? '\n' : ' ');
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
