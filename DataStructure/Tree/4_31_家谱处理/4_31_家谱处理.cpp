// 4_31_家谱处理.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
using namespace std;
int n, m, f[101];
map<string, int> mp;
char name[11], p1[11], p2[11], r[11], pre[101][11];
int main() {
	scanf("%d%d", &n, &m);
	getchar();
	for (int i = 0; i < n; i++) {
		int c = 0, cc = 0;
		while ((name[0] = getchar()) == ' ') c++;
		c /= 2;
		while ((name[++cc] = getchar()) != '\n');
		name[cc] = 0;
		mp[name] = i + 1;
		if (c) f[i + 1] = mp[pre[c - 1]];
		strcpy(pre[c], name);
	}
	for (int i = 0; i < m; i++) {
		scanf("%s%s%s%s%s%s", p1, r, r, r, p2, p2);
		if (!strcmp(r, "child")) puts(f[mp[p1]] == mp[p2] ? "True" : "False");
		else if (!strcmp(r, "parent")) puts(f[mp[p2]] == mp[p1] ? "True" : "False");
		else if (!strcmp(r, "sibling")) puts(f[mp[p1]] == f[mp[p2]] ? "True" : "False");
		else if (!strcmp(r, "descendant")) {
			int a = mp[p1], b = mp[p2];
			while (a && a != b) a = f[a];
			puts(a ? "True" : "False");
		}
		else {
			int a = mp[p2], b = mp[p1];
			while (a && a != b) a = f[a];
			puts(a ? "True" : "False");
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
