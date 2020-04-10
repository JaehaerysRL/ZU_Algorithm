// 7-123 空心字母金字塔 (10分)
//输入一个大写的英文字母，输出空心的字母金字塔。

//输入格式:
//一个大写英文字母。

//输出格式:
//一个空心的大写英文字母金字塔，其中第1层的“A”在第1行的第40列，列从1开始计数。

//输入样例:
//E
//输出样例:
//                                       A
//                                      B B
//                                     C   C
//                                    D     D
//                                   EEEEEEEEE

#include <stdio.h>
int main() {
	char c, temp;
	scanf("%c", &c);
	int n = c - 64;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 40 - i; j++)printf(" ");
		if (i == 1 && i != n) {
			printf("%c\n", 'A');
		}
		else if (i == n) {
			temp = 'A' + i - 1;
			for (int j = 0; j < 2 * i - 1; j++)printf("%c", temp);
		}
		else {
			temp = 'A' + i - 1;
			printf("%c", temp);
			for (int j = 0; j < 2 * i - 3; j++)printf(" ");
			printf("%c\n", temp);
		}
	}
}
