// 7-33 统计素数并求和 (20分)
//本题要求统计给定整数M和N区间内素数的个数并对它们求和。

//输入格式:
//输入在一行中给出两个正整数M和N（1≤M≤N≤500）。

//输出格式:
//在一行中顺序输出M和N区间内素数的个数以及它们的和，数字间以空格分隔。

//输入样例:
//10 31
  
//输出样例:
//7 143

#include <stdio.h>
#include <math.h>

int main()
{
    int M, N, count = 0, sum = 0;
    scanf("%d %d", &M, &N);
    for (int i = M; i <= N; i++)
    {
        int isPrime = 1;
        if (N==1) break;
        if (N==2) {
            count = 1;
            sum = 2;
            break;
        }
        for (int j = 2;j < i;j++)
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        if (isPrime == 1) {
            count++;
            sum += i;
        }
        if (i==1){
            count--;
            sum--;
        }
    }
    printf("%d %d", count, sum);
}