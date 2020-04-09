// 7-87 计算分段函数[1] (10分)
//本题目要求计算下列分段函数f(x)的值：
//f(x)=x^-1(x!=0)
//f(x)=0(x==0)
//输入格式:
//输入在一行中给出实数x。

//输出格式:
//在一行中按“f(x) = result”的格式输出，其中x与result都保留一位小数。

//输入样例1:
//10

//输出样例1:
//f(10.0) = 0.1

#include <stdio.h>
int main() {
	double x, f;
	scanf("%lf", &x);
	if (x == 0) f = 0;
	else f = (double)1 / x;
	printf("f(%.1lf) = %.1lf", x, f);
}