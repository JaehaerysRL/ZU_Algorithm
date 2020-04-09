// 7-96 计算存款利息 (10分)
//本题目要求计算存款利息，计算公式为interest=money×(1+rate)^​year−money，其中interest为存款到期时的利息（税前），money是存款金额，year是存期，rate是年利率。

//输入格式：
//输入在一行中顺序给出三个正实数money、year和rate，以空格分隔。

//输出格式：
//在一行中按“interest = 利息”的格式输出，其中利息保留两位小数。

//输入样例：
//1000 3 0.025

//输出样例：
//interest = 76.89

#include <stdio.h>
#include <math.h>
int main()
{
	double m, y, r, i;
	scanf("%lf %lf %lf", &m, &y, &r);
	i = m * pow(1 + r, y) - m;
	printf("interest = %.2lf", i);
}
