// 4_35_哈夫曼编码.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <queue>
#include <cstring>
#define MAXL 64
using namespace std;

int main()
{
	priority_queue<int, vector<int>, greater<int> > P;
	int N, f;
	cin >> N;
	string c;
	int base[MAXL];
	for (int i = 0; i < N; i++)//顺序相同不用记字母
	{
		cin >> c >> f;
		P.push(f);
		base[i] = f;
	}
	int len = 0;
	while (P.size() >= 2) {
		int x = P.top(); P.pop();
		int y = P.top(); P.pop();
		len += (x + y);
		P.push(x + y);
	}
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		int tLen = 0;
		bool judge = true;
		string ts[MAXL], tCode;
		for (int j = 0; j < N; j++)
		{
			cin >> c >> tCode;
			ts[j] = tCode;//同样顺序相同不用记字母
			tLen += tCode.size() * base[j];
		}
		if (tLen != len) {
			judge = false; goto E;
		}
		else
			for (int j = 0; j < N; j++)
				for (int k = 0; k < N; k++)
					if (k != j && ts[k].size() >= ts[j].size() && ts[k].substr(0, ts[j].size()) == ts[j])
					{
						judge = false; goto E;
					}
	E:
		if (judge) cout << "Yes" << endl;
		else cout << "No" << endl;
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
