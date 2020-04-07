﻿// 7-35 猴子吃桃问题 (15分)
//一只猴子第一天摘下若干个桃子，当即吃了一半，还不过瘾，又多吃了一个；第二天早上又将剩下的桃子吃掉一半，又多吃了一个。以后每天早上都吃了前一天剩下的一半加一个。到第N天早上想再吃时，见只剩下一个桃子了。问：第一天共摘了多少个桃子？

//输入格式:
//输入在一行中给出正整数N（1<N≤10）。

//输出格式:
//在一行中输出第一天共摘了多少个桃子。

//输入样例:
//3
 
//输出样例:
//10

#include <stdio.h>
#include <math.h>

int main()
{
    int N, sum = 1, temp = 0;
    scanf("%d", &N);
    for (int i = 1; i < N; i++)
    {
        temp = sum;
        sum = (sum + 1) * 2;
        if (sum / 2 != temp + 1) sum--;
    }
    printf("%d", sum);
}
