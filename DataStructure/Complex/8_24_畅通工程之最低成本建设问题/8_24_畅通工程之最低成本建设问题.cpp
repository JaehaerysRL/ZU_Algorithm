// 8_24_畅通工程之最低成本建设问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int f[1001];
typedef struct E {
	int xx;
	int yy;
	int zz;
}E;
E edge[3001];
bool cmp(E a, E b) {
	return a.zz < b.zz;
}
int getf(int x) {
	if (f[x] == x)
		return x;
	f[x] = getf(f[x]);
	return f[x];
}
int merge(int x, int y) {
	int tx = getf(x);
	int ty = getf(y);
	if (tx != ty) {
		f[ty] = tx;
		return 1;
	}
	return 0;
}
int main() {
	int n, e;
	scanf("%d %d", &n, &e);
	for (int i = 1; i <= n; i++)
		f[i] = i;
	for (int i = 0; i < e; i++)
		scanf("%d %d %d", &edge[i].xx, &edge[i].yy, &edge[i].zz);
	//排序
	sort(edge, edge + e, cmp);
	int cnt = 0;//计算边数
	int sum = 0;
	for (int i = 0; i < e; i++) {
		if (merge(edge[i].xx, edge[i].yy)) {//如果edge[i].xx,edge[i].yy已经没有通过别的点连接
			cnt++;
			sum += edge[i].zz;
		}
		if (cnt == n - 1)//选择了n-1条边
			break;
	}
	int sm = 0;
	for (int i = 1; i <= n; i++)
		f[i] == i ? sm++ : sm;
	if (sm > 1 || !sm)
		printf("Impossible\n");
	else
		printf("%d\n", sum);
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
