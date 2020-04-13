// 6-1 使用函数求素数和 (20分)
//本题要求实现一个判断素数的简单函数、以及利用该函数计算给定区间内素数和的函数。
//素数就是只能被1和自身整除的正整数。注意：1不是素数，2是素数。

//输入样例：
//-1 10

//输出样例：
//Sum of ( 2 3 5 7 ) = 17

#include <stdio.h>
#include <math.h>

int prime( int p );
int PrimeSum( int m, int n );

int main()
{
    int m, n, p;

    scanf("%d %d", &m, &n);
    printf("Sum of ( ");
    for( p=m; p<=n; p++ ) {
        if( prime(p) != 0 )
            printf("%d ", p);
    }
    printf(") = %d\n", PrimeSum(m, n));

    return 0;
}

/* 你的代码将被嵌在这里 */
int prime(int p) {
    int judge = 1;
    if (p <= 1)judge = 0;
    if (p % 2 == 0 && p != 2) judge = 0;
    else {
        for (int i = 3; i <= sqrt(p); i = i + 2)
        {
            if (p % i == 0 || p % 2 == 0) {
                judge = 0;
                break;
            }
        }
    }
    return judge;
}

int PrimeSum(int m, int n) {
    int sum = 0;
    for (int i = m; i <= n; i++) {
        if (prime(i) != 0)sum += i;
    }
    return sum;
}