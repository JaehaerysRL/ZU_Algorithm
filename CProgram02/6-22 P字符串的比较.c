// 6-22 P字符串的比较 (5分)
//P字符串是另一种字符串实现形式。它也采用char数组来保存字符串中的字符，但是最后一个字符后面没有结尾的'\0'。它使用另一个int类型的变量来表示字符串中的字符的个数。
//本题要求编写P字符串的比较函数。
//pstr_cmp比较两个字符串的大小，如果两个字符串完全相同，则返回0；否则，返回第一个不相同的字符的差值（s1的那个字符减s2的那个字符的差）。如果两个字符串的长度不同，但是短的字符串正好是长的字符串的开头的所有字符，则用长的字符串多余部分的第一个字符的值作为差值。如hell和hellA的差值是-65。

输入样例：
123A 123
 
输出样例：
65

#include <stdio.h>

const int SIZE = 80;

//	这两个函数由裁判程序提供
int pstr_scan(char* str, int size);
void pstr_print(const char* str, int length);

int pstr_cmp(const char *s1, int len1, const char *s2, int len2);

int main()
{
	char line[SIZE];
	char text[SIZE];
	
	int len1 = pstr_scan(line, SIZE);
	int len2 = pstr_scan(text, SIZE);

	printf("%d\n", pstr_cmp(line, len1, text, len2));
	
  return 0;
}

/* 请在这里填写答案 */
int pstr_cmp(const char* s1, int len1, const char* s2, int len2) {
	int sum = 0, i = 0;
	int n = len1 > len2 ? len1 : len2;
	for (int i = 0; i < n; i++)
	{
		if (s1[i]!=s2[i]) {
			sum = s1[i] - s2[i];
			break;
		}
	}
	return sum;
}