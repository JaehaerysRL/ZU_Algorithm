// 7-17 最长对称子串 (25分)
//对给定的字符串，本题要求你输出最长对称子串的长度。例如，给定Is PAT&TAP symmetric?，最长对称子串为s PAT&TAP s，于是你应该输出11。

//输入格式：
//输入在一行中给出长度不超过1000的非空字符串。

//输出格式：
//在一行中输出最长对称子串的长度。

//输入样例：
//Is PAT&TAP symmetric?

//输出样例：
//11

#include <stdio.h>
#include <string.h>

int main()
{
	int maxLen = 1;
	char s[1001];
	gets(s);
	int n = strlen(s);
	for (int i = 1; i < n - 1; i++)
	{
		int len = 1, left = i, right = i;
		//先定出核心
		while (left != 0 && s[left - 1] == s[i]) {
			left--;
			len++;
		}
		while (right != n - 1 && s[right + 1] == s[i]) {
			right++;
			len++;
		}
		//左右扫略
		while (left != 0 && right != n - 1) {
			if (s[left - 1] == s[right + 1]) {
				left--;
				right++;
				len += 2;
			}
			else break;
		}
		if (len > maxLen) maxLen = len;
	}
	printf("%d", maxLen);
}