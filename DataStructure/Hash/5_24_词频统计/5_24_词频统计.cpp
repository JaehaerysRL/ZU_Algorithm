// 5_24_词频统计.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(pair<string, int> a, pair <string, int> b) {
	if (a.second > b.second)
		return true;
	else if (a.second == b.second && a.first < b.first)
		return true;
	else return false;
}

int main()
{
	char ch;
	string s;
	map<string, int> m;
	do {
		ch = getchar();
		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') || ch == '_') {
			if (s.size() <= 14) {
				if (ch >= 'A' && ch <= 'Z') ch += 32;
				s += ch;
			}
		}
		else {
			if((s.size() > 0)) m[s]++;
			s.clear();
		}
	} while (ch != '#');
	vector<pair<string, int>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), cmp);
	cout << v.size() << endl;
	int n = (int)(m.size() * 0.1);
	for (int i = 0; i < n; i++)
		cout << v[i].second << ":" << v[i].first << endl;
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
