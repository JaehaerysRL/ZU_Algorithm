// 7-48 字符串转换成十进制整数 (15分)
//输入一个以#结束的字符串，本题要求滤去所有的非十六进制字符（不分大小写），组成一个新的表示十六进制数字的字符串，然后将其转换为十进制数后输出。如果在第一个十六进制字符之前存在字符“-”，则代表该数是负数。

//输入格式：
//输入在一行中给出一个以#结束的非空字符串。

//输出格式：
//在一行中输出转换后的十进制数。题目保证输出在长整型范围内。

//输入样例：
//+-P-xf4+-1!#

//输出样例：
//-3905

#include <stdio.h>
#include <math.h>

int htot(char h) {
	int t = -1;
	if (h >= 48 && h <= 57) t = h - 48;
	else if (h >= 65 && h <= 70)t = h - 65 + 10;
	else if (h >= 97 && h <= 102)t = h - 97 + 10;
	return t;
}

int main()
{
	int sig = 1, count = 0;
	char tmp;
	int num[100];
	do
	{
		scanf("%c", &tmp);
		int t;
		if (sig == 1 && tmp == '-' && count == 0) sig = -1;
		if ((tmp >= 48 && tmp <= 57) || (tmp >= 65 && tmp <= 70) || (tmp >= 97 && tmp <= 102)) {
			t = htot(tmp);
			num[count++] = t;
		}
	} while (tmp!='#');
	long final = 0;
	for (int i = 0; i < count; i++)
	{
		final += pow(16, i) * num[count - 1 - i];
	}
	final *= sig;
	printf("%ld", final);
}