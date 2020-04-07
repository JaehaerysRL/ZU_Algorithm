﻿// 7-34 求分数序列前N项和 (15分)
//本题要求编写程序，计算序列 2/1+3/2+5/3+8/5+... 的前N项之和。注意该序列从第2项起，每一项的分子是前一项分子与分母的和，分母是前一项的分子。

//输入格式:
//输入在一行中给出一个正整数N。

//输出格式:
//在一行中输出部分和的值，精确到小数点后两位。题目保证计算结果不超过双精度范围。

//输入样例:
//20
  
//输出样例:
//32.66

#include <stdio.h>
#include <math.h>

int main()
{
    double N, a = 0, b = 1, x = 1, y = 1, sum = 0;
    scanf("%lf", &N);
    for (int i = 0; i < N; i++)
    {
        y = x;
        a = b;
        b = x;
        x = a + b;
        sum += x / y;
    }
    printf("%.2lf", sum);
}