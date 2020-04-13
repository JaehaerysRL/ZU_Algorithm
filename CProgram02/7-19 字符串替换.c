// 7-19 字符串替换 (15分)
//本题要求编写程序，将给定字符串中的大写英文字母按以下对应规则替换：
//原字母	对应字母
//A	Z
//B	Y
//…	…
//Z	A
//输入格式：
//输入在一行中给出一个不超过80个字符、并以回车结束的字符串。

//输出格式：
//输出在一行中给出替换完成后的字符串。

//输入样例：
//Only the 11 CAPItaL LeTtERS are replaced.

//输出样例：
//Lnly the 11 XZKRtaO OeGtVIH are replaced.

#include <stdio.h>
#include <string.h>
int main() {
	char str[81];
	gets(str);
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		if (str[i] >= 65 && str[i] <= 90) str[i] = 155 - str[i];
	}
	for (int i = 0; i < len; i++)
	{
		printf("%c", str[i]);
	}
}