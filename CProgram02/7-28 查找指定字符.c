// 7-28 查找指定字符 (15分)
//本题要求编写程序，从给定字符串中查找某指定的字符。

//输入格式：
//输入的第一行是一个待查找的字符。第二行是一个以回车结束的非空字符串（不超过80个字符）。

//输出格式：
//如果找到，在一行内按照格式“index = 下标”输出该字符在字符串中所对应的最大下标（下标从0开始）；否则输出"Not Found"。

//输入样例1：
//m
//programming

//输出样例1：
//index = 7

#include <stdio.h>
#include <string.h>

int main()
{
	int index, flag = 0;
	char c;
	char s[81];
	scanf("%c", &c);
	getchar();
	gets(s);
	int n = strlen(s);
	for (int i = 0; i < n; i++)
	{
		if (s[i] == c) {
			flag = 1;
			index = i;
		}
	}
	if (flag == 1) printf("index = %d", index);
	else printf("Not Found");
}
