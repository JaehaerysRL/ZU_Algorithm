// 7-38 支票面额 (15分)
//一个采购员去银行兑换一张y元f分的支票，结果出纳员错给了f元y分。采购员用去了n分之后才发觉有错，于是清点了余额尚有2y元2f分，问该支票面额是多少？

//输入格式：
//输入在一行中给出小于100的正整数n。

//输出格式：
//在一行中按格式y.f输出该支票的原始面额。如果无解，则输出No Solution。

//输入样例1：
//23
 
//输出样例1：
//25.51

#include <stdio.h>
#include <math.h>

int main()
{
    int n, y, f;
    scanf("%d", &n);
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (98 * i - 199 * j == n) {
                f = i;
                y = j;
                goto SUC;
            }
        }
    }
    printf("No Solution");
    return 0;
SUC:printf("%d.%d",y,f);
    return 0;
}