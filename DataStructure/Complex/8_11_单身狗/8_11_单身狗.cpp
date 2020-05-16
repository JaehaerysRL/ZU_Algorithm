// 8_11_单身狗.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	map<int, int> mp;
	map<int, int>::iterator iterm;
	vector<int> v;
	vector<int>::iterator iterv;
	vector<int> s;
	int N, M, X, Y;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		scanf_s("%d %d", &X, &Y);
		mp[X] = Y;
		mp[Y] = X;
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		scanf_s("%d", &X);
		v.emplace_back(X);
	}
	int cnt = 0;
	for (int i = 0; i < M; i++)
	{
		iterm = mp.find(v[i]);
		iterv = find(v.begin(), v.end(), mp[v[i]]);
		if (iterm == mp.end() || iterv == v.end()) {
			s.emplace_back(v[i]);
			cnt++;
		}	
	}
	sort(s.begin(), s.end());
	cout << cnt << endl;
	if(cnt > 0){
		printf("%05d", s[0]);
		for (int i = 1; i < cnt; i++)
			printf(" %05d", s[i]);
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
