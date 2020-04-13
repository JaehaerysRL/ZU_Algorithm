// 7-12 字符串逆序 (15分)
//输入一个字符串，对该字符串进行逆序，输出逆序后的字符串。

//输入格式：
//输入在一行中给出一个不超过80个字符长度的、以回车结束的非空字符串。

//输出格式：
//在一行中输出逆序后的字符串。

//输入样例：
//Hello World!

//输出样例：
//!dlroW olleH

#include <stdio.h>
#include <string.h>

int main()
{
	char s[81];
	gets(s);
	int n = strlen(s);
	for (int i = n-1; i >= 0; i--)
	{
		printf("%c", s[i]);
	}
}