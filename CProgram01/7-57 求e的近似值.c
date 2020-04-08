// 7-57 求e的近似值 (15分)
//自然常数 e 可以用级数 1+1/1!+1/2!+⋯+1/n!+⋯ 来近似计算。本题要求对给定的非负整数 n，求该级数的前 n+1 项和。

//输入格式:
//输入第一行中给出非负整数 n（≤1000）。

//输出格式:
//在一行中输出部分和的值，保留小数点后八位。

//输入样例:
//10
 
//输出样例:
//2.71828180

#include <stdio.h>
double fact(int n) {
	double p = 1;
	for (int i = 1; i <= n; i++)
	{
		p *= i;
	}
	return 1/p;
}
int main() {
	int N;
	double e=0;
	scanf("%d", &N);
	for (int i = 0; i <= N; i++)
	{
		e += fact(i);
	}
	printf("%.8lf", e);
}