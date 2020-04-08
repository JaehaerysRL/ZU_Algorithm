// 7-58 求幂级数展开的部分和 (20分)
//已知函数e^x可以展开为幂级数1+x+x^2/2!+x^3/3!+⋯+x^k/k!+⋯。现给定一个实数x，要求利用此幂级数部分和求e^​x的近似值，求和一直继续到最后一项的绝对值小于0.00001。

//输入格式:
//输入在一行中给出一个实数x∈[0,5]。

//输出格式:
//在一行中输出满足条件的幂级数部分和，保留小数点后四位。

//输入样例:
//1.2

//输出样例:
//3.3201

#include <stdio.h>
#include <math.h>
double fact(int n) {
	double p = 1;
	for (int i = 1; i <= n; i++)
	{
		p *= i;
	}
	p = 1 / p;
	return p;
}
int main() {
	double x, s = 0, temp;
	scanf("%lf", &x);
	int i = 0;
	do
	{
		temp = (double)pow(x, i) * fact(i);
		s += temp;
		i++;
	} while (temp >= 0.000001);
	printf("%.4lf", s);
}
