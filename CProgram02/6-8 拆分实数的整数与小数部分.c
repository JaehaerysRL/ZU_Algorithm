// 6-8 拆分实数的整数与小数部分 (15分)
//本题要求实现一个拆分实数的整数与小数部分的简单函数。

//输入样例：
//2.718

//输出样例：
//The integer part is 2
//The fractional part is 0.718

#include <stdio.h>

void splitfloat( float x, int *intpart, float *fracpart );

int main()
{
    float x, fracpart;
    int intpart;

    scanf("%f", &x);
    splitfloat(x, &intpart, &fracpart);
    printf("The integer part is %d\n", intpart);
    printf("The fractional part is %g\n", fracpart);

    return 0;
}

/* 你的代码将被嵌在这里 */
void splitfloat(float x, int* intpart, float* fracpart) {
    *intpart = (int)x;
    *fracpart = x - *intpart;
}