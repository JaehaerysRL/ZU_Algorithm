// 7-3 近似求PI (15分)
//根据下面关系式，求圆周率的值，直到最后一项的值小于给定阈值。
​//π/2​=1+1/3+2!/(3*5)+……+n!/(3*5*……*(2n+1))+……

//输入格式：
//输入在一行中给出小于1的阈值。

//输出格式：
//在一行中输出满足阈值条件的近似圆周率，输出到小数点后6位。

//输入样例：
//0.01

//输出样例：
//3.132157

#include <stdio.h>
double fact(int n) {
	double p = 1;
	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 0) p *= (double)i;
	}
	if (n % 2 == 0) for (int i = n + 1; i <= 2 * n + 1; i = i + 2)p = p / (double)i;
	else for (int i = n + 2; i <= 2 * n + 1; i = i + 2)p = p / (double)i;
	return p;
}

int main()
{
	double x;
	scanf("%lf", &x);
	double temp = 1, sum = 1;
	int i = 1;
	do
	{
		temp = fact(i);
		sum += temp;
		i++;
	} while (temp>=x);
	printf("%.6lf", 2 * sum);
}