// 5_32_新浪微博热门话题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <map>
#include <string>
#include <cstring>
#define MAXN 150
using namespace std;
typedef char str[MAXN];

int main()
{
	map<string, int> num;//某话题出现次数
	int N, sum = 0, max = 0, sp = 0;
	str s, h;
	char c;
	cin >> N; cin.get();
	for (int i = 0; i < N; i++)
	{
		map<string, bool> flag;
		while ((c = tolower(cin.get())) != '\n')
			if (c == '#') {
				sp = 0;
				while ((c = tolower(cin.get())) != '#') {
					if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
						s[sp++] = c;
					else if (sp && (s[sp - 1] >= 'a' && s[sp - 1] <= 'z') || (s[sp - 1] >= '0' && s[sp - 1] <= '9'))
						s[sp++] = ' ';
				}
				if (sp && s[sp - 1] == ' ') sp--;
				s[sp] = '\0';
				if (!flag[s]) {
					num[s]++;
					flag[s] = true;
					if (num[s] > max) {
						max = num[s];
						sum = 0;
						strcpy(h, s);
					}
					else if (num[s] == max) {
						sum++;
						if (strcmp(s, h) < 0)
							strcpy(h, s);
					}
				}
			}
	}
	h[0] = toupper(h[0]);
	cout << h << endl << max << endl;
	if (sum > 0)
		cout << "And " << sum << " more ...";
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
