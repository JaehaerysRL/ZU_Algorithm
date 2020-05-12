// 8_31_KMP串的模式匹配.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void bulidmatch(string pattern, vector<int>& match, int m)
{
	match[0] = -1;
	int j = 1;
	while (j < m)
	{
		int i = match[j - 1];
		while (i >= 0)
		{
			if (pattern[i + 1] == pattern[j])
			{
				match[j] = i + 1;
				break;
			}
			else
				i = match[i];
		}
		if (i == -1)
			match[j] = ((pattern[j] == pattern[0]) ? 0 : -1);
		j++;
	}
}

int KMPIndex(string S, string P, int n, int m) {
	if (n < m)
		return -1;
	vector<int> match(m);
	bulidmatch(P, match, m);
	int s = 0, p = 0;
	while (s < n && p < m)
	{
		if (S[s] == P[p])
		{
			s++;p++;
		}
		else
		{
			if (p > 0)
				p = match[p - 1] + 1;
			else
			{
				p = 0;
				s++;
			}
		}
	}
	if (p == m)
		return s - m;
	else
		return -1;
}

int main()
{
	string String, Pattern;
	int N, sLen, pLen;
	cin >> String >> N;
	sLen = String.size();
	for (int i = 0; i < N; i++)
	{
		cin >> Pattern;
		pLen = Pattern.size();
		int pos = KMPIndex(String, Pattern, sLen, pLen);
		if (pos < 0) cout << "Not Found" << endl;
		else cout << String.substr(pos) << endl;
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
