// 7-22 统计字符出现次数 (20分)
//本题要求编写程序，统计并输出某给定字符在给定字符串中出现的次数。

//输入格式：
//输入第一行给出一个以回车结束的字符串（少于80个字符）；第二行输入一个字符。

//输出格式：
//在一行中输出给定字符在给定字符串中出现的次数。

//输入样例：
//programming is More fun!
//m

//输出样例：
//2

#include <stdio.h>
#include <string.h>

int main()
{
	char s[81];
	gets(s);
	int n = strlen(s), len = 1;
	char cha[n];
	int freq[n];
	cha[0] = s[0];
	freq[0] = 1;
	for (int i = 1; i < n; i++)
	{
		int flag = 0;
		for (int j = 0; j < len; j++)
		{
			if (s[i] == cha[j]) {
				flag = 1;
				freq[j]++;
				break;
			}
		}
		if (flag == 0) {
			cha[len] = s[i];
			freq[len] = 1;
			len++;
		}
	}
	char c;
	scanf("%c", &c);
	int flag = 0;
	for (int i = 0; i < len; i++)
	{
		if (cha[i] == c) {
			printf("%d", freq[i]);
			flag = 1;
			break;
		}
	}
	if (flag == 0)printf("%d", 0);
}
