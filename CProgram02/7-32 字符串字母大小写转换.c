// 7-32 字符串字母大小写转换 (15分)
//本题要求编写程序，对一个以“#”结束的字符串，将其小写字母全部转换成大写字母，把大写字母全部转换成小写字母，其他字符不变输出。

//输入格式：
//输入为一个以“#”结束的字符串（不超过30个字符）。

//输出格式：
//在一行中输出大小写转换后的结果字符串。

//输入样例：
//Hello World! 123#

//输出样例：
//hELLO wORLD! 123

#include <stdio.h>
#include <string.h>

int main()
{
	char s[36];
	gets(s);
	int n = strlen(s);
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '#')break;
		else if (s[i] >= 65 && s[i] <= 90) s[i] += 32;
		else if (s[i] >= 97 && s[i] <= 122) s[i] -= 32;
		printf("%c", s[i]);
	}
}