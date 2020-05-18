// 8_21_银行排队问题之单队列多窗口服务.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#define MAXN 1001
#define MAXW 10
using namespace std;

struct waiter
{
	int t, h, length;
} a[MAXN];

int x[MAXW] = { 0 };//柜台时间
int c[MAXW] = { 0 };//计数客户、
int len = 0;
int main()
{
	int n, k;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].t >> a[i].h;
		if (a[i].h > 60)a[i].h = 60;//事务被处理的最长时间为60分钟
	}
	cin >> k;
	for (int i = 1; i <= n; i++) {
		int pai = 1;//有多个窗口可选择时，顾客总是选择编号最小的窗口。
		for (int j = 1; j <= k; j++) {
			if (x[pai] > x[j])pai = j;//哪个柜台更早空闲
			if (a[i].t >= x[pai])break;//顾客到来有空闲窗口
		}
		if (a[i].t >= x[pai]) {
			x[pai] = a[i].t + a[i].h;//窗口时间更新
			a[i].length = 0;//顾客无需等待
		}
		else {
			a[i].length = x[pai] - a[i].t;//顾客等待时间
			x[pai] = x[pai] + a[i].h;//窗口时间更新
		}
		c[pai]++;//窗口处理顾客人数更新
	}
	int sum = 0, sum2 = 0, sum3 = 0;
	for (int i = 1; i <= n; i++) {
		if (sum2 < a[i].length)sum2 = a[i].length;//最长等待时间
		sum += a[i].length;//总的等待时间
	}
	for (int i = 1; i <= k; i++) {
		if (sum3 < x[i])sum3 = x[i];//窗口最长的时间也就是全部完成的时间
	}
	printf("%.1lf ", sum * 1.0 / n);
	cout << sum2 << " " << sum3 << endl;
	for (int i = 1; i <= k; i++) {
		if (i != 1)cout << " ";
		cout << c[i];
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
