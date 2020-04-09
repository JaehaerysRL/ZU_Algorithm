// 7-74 三角形判断 (15分)
//给定平面上任意三个点的坐标(x​1,y1)、(x2,y2)、(x3,y3)，检验它们能否构成三角形。

//输入格式:
//输入在一行中顺序给出六个[−100,100]范围内的数字，即三个点的坐标x

//输出格式:
//若这3个点不能构成三角形，则在一行中输出“Impossible”；若可以，则在一行中输出该三角形的周长和面积，格式为“L = 周长, A = 面积”，输出到小数点后2位。

//输入样例1:
//4 5 6 9 7 8
  
//输出样例1:
//L = 10.13, A = 3.00

#include <stdio.h>
#include <math.h>
double pd(double x1, double y1, double x2, double y2) {
	double d = pow(pow(x2 - x1, 2) + pow(y2 - y1, 2), 0.5);
	return d;
}
int main() {
	double x1, y1, x2, y2, x3, y3, a, b, c;
	scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
	a = pd(x1, y1, x2, y2);
	b = pd(x1, y1, x3, y3);
	c = pd(x3, y3, x2, y2);
	if (a + b <= c) goto END;
	if (a + c <= b) goto END;
	if (b + c <= a) goto END;
	double s, l;
	l = a + b + c;
	double m = 0.5 * l;
	s = pow(m * (m - a) * (m - b) * (m - c), 0.5);
	printf("L = %.2lf, A = %.2lf", l, s);
	return 0;
END:printf("Impossible");
	return 0;
}