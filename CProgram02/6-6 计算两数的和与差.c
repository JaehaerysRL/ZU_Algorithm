// 6-6 计算两数的和与差 (10分)
//本题要求实现一个计算输入的两数的和与差的简单函数。

//输入样例：
//4 6

//输出样例：
//The sum is 10.00
//The diff is -2.00

#include <stdio.h>

void sum_diff( float op1, float op2, float *psum, float *pdiff );

int main()
{
    float a, b, sum, diff;

    scanf("%f %f", &a, &b);
    sum_diff(a, b, &sum, &diff);
    printf("The sum is %.2f\nThe diff is %.2f\n", sum, diff);
	
    return 0; 
}

/* 你的代码将被嵌在这里 */
void sum_diff(float op1, float op2, float* psum, float* pdiff) {
    *psum = op1 + op2;
    *pdiff = op1 - op2;
}