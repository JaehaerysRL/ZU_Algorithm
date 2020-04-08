// 7-64 统计大写辅音字母 (15分)
//英文辅音字母是除A、E、I、O、U以外的字母。本题要求编写程序，统计给定字符串中大写辅音字母的个数。

//输入格式：
//输入在一行中给出一个不超过80个字符、并以回车结束的字符串。

//输出格式：
//输出在一行中给出字符串中大写辅音字母的个数。

//输入样例：
//HELLO World!
 
//输出样例：
//4

#include <stdio.h>
#include <string.h>
int main() {
	char str[81];
	gets(str);
	int len = strlen(str);
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] >= 66 && str[i] <= 90 && str[i] != 69 && str[i] != 73 && str[i] != 79 && str[i] != 85) count++;
	}
	printf("%d",count);
}