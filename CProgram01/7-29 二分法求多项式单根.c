// 7-29 二分法求多项式单根 (20分)
//二分法求函数根的原理为：如果连续函数f(x)在区间[a,b]的两个端点取值异号，即f(a)f(b)<0，则它在这个区间内至少存在1个根r，即f(r)=0。

//二分法的步骤为：检查区间长度，如果小于给定阈值，则停止，输出区间中点(a+b)/2；否则
//如果f(a)f(b)<0，则计算中点的值f((a+b)/2)；
//如果f((a+b)/2)正好为0，则(a+b)/2就是要求的根；否则
//如果f((a+b)/2)与f(a)同号，则说明根在区间[(a+b)/2,b]，令a=(a+b)/2，重复循环；
//如果f((a+b)/2)与f(b)同号，则说明根在区间[a,(a+b)/2]，令b=(a+b)/2，重复循环。
//本题目要求编写程序，计算给定3阶多项式在给定区间[a,b]内的根。

//输入格式：
//输入在第1行中顺序给出多项式的4个系数a​3、a​2、a1、a0，在第2行中顺序给出区间端点a和b。题目保证多项式在给定区间内存在唯一单根。

//输出格式：
//在一行中输出该多项式在该区间内的根，精确到小数点后2位。

//输入样例：
//3 -1 -3 1
//-0.5 0.5
   
//输出样例：
//0.33

#include <stdio.h>

double fx(double a3, double a2, double a1, double a0, double x) {
	return ((a3 * x + a2) * x + a1) * x + a0;
}

int main()
{
	double a3, a2, a1, a0, a, b, mid, root, fa, fb, fm;
	scanf("%lf %lf %lf %lf", &a3, &a2, &a1, &a0);
	scanf("%lf %lf", &a, &b);
	do{
		mid = (a + b) / 2;
		if (b - a < 0.015) {
			root = mid;
			break;
		}
		fa = fx(a3, a2, a1, a0, a);
		if (fa == 0) {
			root = a;
			break;
		}
		fb = fx(a3, a2, a1, a0, b);
		if (fb == 0) {
			root = b;
			break;
		}
		fm = fx(a3, a2, a1, a0, mid);
		if (fm == 0) {
			root = mid;
			break;
		}
		if (fm * fa < 0) b = mid;
		else a = mid;
	}while (1);
	printf("%.2lf", root);
}