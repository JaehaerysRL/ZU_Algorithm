// 8_25_畅通工程之局部最小花费问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <memory.h>
#define inf 0x3f3f3f3f
#define MAX 1e9;

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int maxn = 5000;
int vis[maxn], pre[maxn];
int N;
struct edge {
	int st, en, co;
}e[maxn];

void init() {
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= N; i++) {//注意pre数组的初始化
		pre[i] = i;
	}
	int st, en, co, state, k = N * (N - 1) / 2;
	for (int i = 0; i < k; i++) {
		scanf("%d %d %d %d", &st, &en, &co, &state);
		e[i].st = st;
		e[i].en = en;
		if (state) {
			e[i].co = 0;
		}
		else {
			e[i].co = co;
		}
	}
}

int Find(int x) {//查找x点的祖先
	return pre[x] == x ? x : pre[x] = Find(pre[x]);
}

bool cmd(edge a, edge b) {
	return a.co < b.co;
}

void solve() {
	int ans = 0, cnt = 0, k = N * (N - 1) / 2;
	for (int i = 0; i < k; i++) {
		edge te = e[i];
		int tx = Find(te.st), ty = Find(te.en);
		if (tx != ty) {//如果两个点不在同一个集合中,就通过并查集将两个点放在一个集合中
			cnt++;
			ans += te.co;
			pre[tx] = ty;
		}
		if (cnt == N - 1)//当确定的边数到达规定的数量的时候，就推出循环
			break;
	}
	printf("%d\n", ans);
}

int main() {
	scanf("%d", &N);
	init();
	int k = (N - 1) * N / 2;
	sort(e, e + k, cmd);//将所有的边的权值按从小到大进行排序
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
