// 7-23 IP地址转换 (20分)
//一个IP地址是用四个字节（每个字节8个位）的二进制码组成。请将32位二进制码表示的IP地址转换为十进制格式表示的IP地址输出。

//输入格式：
//输入在一行中给出32位二进制字符串。

//输出格式：
//在一行中输出十进制格式的IP地址，其由4个十进制数组成（分别对应4个8位的二进制数），中间用“.”分隔开。

//输入样例：
//11001100100101000001010101110010

//输出样例：
//204.148.21.114

#include <stdio.h>
#include <math.h>

int btot(int b) {
	int t = 0, tmp;
	for (int i = 0; i < 8; i++)
	{
		tmp = b % 10;
		b /= 10;
		t += tmp * pow(2, i);
	}
	return t;
}

int main()
{
	int a, p;
	scanf("%8d", &a);
	p = btot(a);
	printf("%d", p);
	for (int i = 0; i < 3; i++)
	{
		scanf("%8d", &a);
		p = btot(a);
		printf(".%d", p);
	}
}