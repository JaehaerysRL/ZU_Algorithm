// 6-28 牛顿迭代求平方根 (10分)
//用牛顿迭代法求非负整数的平方根。 使用1作为猜测的初始值，不要对0做特别判断。
//x：要求平方根的非负整数； eps：当求得的平方根的平方与x的差小于eps值停止迭代。

//输入样例：
//319 0.01
 
//输出样例：
//17.8606

#include <stdio.h>

double ntsqrt(int x, double eps);

int main()
{
  int x;
  double eps;

  scanf("%d %lf", &x, &eps);

  printf("%.4f", ntsqrt(x, eps));

  return 0;
}

/* 请在这里填写答案 */
double ntsqrt(int x, double eps) {
    double a = 1, b;
    while (a*a-x>eps || a*a-x<eps)
    {
        b = (a + x / a) / 2;
        if (a == b || a*a < eps) break;
        else a = b;
    }
    return a;
}