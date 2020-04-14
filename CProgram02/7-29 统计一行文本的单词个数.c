// 7-29 统计一行文本的单词个数 (15分)
//本题目要求编写程序统计一行字符中单词的个数。所谓“单词”是指连续不含空格的字符串，各单词之间用空格分隔，空格数可以是多个。

//输入格式:
//输入给出一行字符。
//输出格式:
//在一行中输出单词个数。

//输入样例:
//Let's go to room 209.
 
//输出样例:
//5

#include <stdio.h>
#include <string.h>

int main()
{
	char s[10000];
	gets(s);
	int n = strlen(s);
	int flag = 0, count = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] != ' ' && s[i] != '\n') {
			if (flag == 0) {
				flag = 1;
				count++;
			}
		}
		else {
			if (flag == 1) flag = 0;
		}
	}
	printf("%d", count);
}