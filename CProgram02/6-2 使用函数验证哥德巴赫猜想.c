// 6-2 使用函数验证哥德巴赫猜想 (20分)
//本题要求实现一个判断素数的简单函数，并利用该函数验证哥德巴赫猜想：任何一个不小于6的偶数均可表示为两个奇素数之和。素数就是只能被1和自身整除的正整数。注意：1不是素数，2是素数。

//输入样例：
//89 100

//输出样例：
//89 is a prime number
//90=7+83, 92=3+89, 94=5+89, 96=7+89, 98=19+79
//100=3+97, 

#include <stdio.h>
#include <math.h>

int prime( int p );
void Goldbach( int n );

int main()
{
    int m, n, i, cnt;

    scanf("%d %d", &m, &n);
    if ( prime(m) != 0 ) printf("%d is a prime number\n", m);
    if ( m < 6 ) m = 6;
    if ( m%2 ) m++;
    cnt = 0;
    for( i=m; i<=n; i+=2 ) {
        Goldbach(i);
        cnt++;
        if ( cnt%5 ) printf(", ");
        else printf("\n");
    }

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

void Goldbach(int n) {
    int p, q;
    for (int i = 3; i <= n-3; i+=2)
    {
        p = i;
        q = n - p;
        if (prime(p) && prime(q)) break;
    }
    printf("%d=%d+%d", n, p, q);
}