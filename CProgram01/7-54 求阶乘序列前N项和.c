// 7-54 求阶乘序列前N项和 (15分)
//本题要求编写程序，计算序列 1!+2!+3!+⋯ 的前N项之和。

//输入格式:
//输入在一行中给出一个不超过12的正整数N。

//输出格式:
//在一行中输出整数结果。

//输入样例:
//5
 
//输出样例:
//153

#include <stdio.h>
long fact(int n) {
	long p = 1;
	for (int i = 1; i <= n; i++)
	{
		p *= i;
	}
	return p;
}
int main() {
	int N;
	long s = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		s += fact(i);
	}
	printf("%ld", s);
}