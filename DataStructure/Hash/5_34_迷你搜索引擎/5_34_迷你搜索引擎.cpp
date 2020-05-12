// 5_34_迷你搜索引擎.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <cctype>
#include <set>
using namespace std;
unordered_map<string, short> pos;///字符串映射为int
vector<short> f[1000][100];///记录字符串对应文件号包含的行号
char s[100][101][51], name[100][51], str[101], sear[10][11], ch;
int no;

int main() {
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		getchar();
		int c = 0, d = 0, e = 0;
		while ((name[i][c] = getchar()) != '\n') c++;
		name[i][c] = 0;
		c = 0;
		while ((ch = getchar()) && ch != '#') {
			if (ch == ' ' || ch == '\n') {
				str[e] = 0;
				if (!pos[str]) pos[str] = ++no;
				f[pos[str]][i].push_back(c);
				e = 0;
				if (ch == '\n') {
					s[i][c][d] = 0;
					d = 0;
					c++;
					continue;
				}
			}
			else str[e++] = tolower(ch);
			s[i][c][d++] = ch;
		}
	}
	scanf("%d", &m);
	getchar();
	while (m--) {
		int c = 0, nn = 0;
		set<int> ans[100];///记录输出的行号
		while ((ch = getchar()) != '\n') {
			if (ch == ' ') sear[nn++][c] = 0, c = 0;
			else sear[nn][c++] = tolower(ch);
		}
		sear[nn++][c] = 0;//
		int ansnum[100];
		int num = 0, j;
		for (int i = 0; i < n; i++) {
			for (j = 0; j < nn; j++) {
				if (f[pos[sear[j]]][i].empty()) break;
			}
			if (j < nn) continue;
			ansnum[num++] = i;
			for (int j = 0; j < nn; j++) {
				int d = pos[sear[j]];
				for (auto it = f[d][i].begin(); it != f[d][i].end(); it++) {
					ans[i].insert(*it);
				}
			}
		}
		printf("%d\n", num);
		if (!num) printf("Not Found\n");
		for (int i = 0; i < num; i++) {
			int d = ansnum[i];
			printf("%s\n", name[d]);
			for (auto it = ans[d].begin(); it != ans[d].end(); it++) {
				printf("%s\n", s[d][*it]);
			}
		}
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
