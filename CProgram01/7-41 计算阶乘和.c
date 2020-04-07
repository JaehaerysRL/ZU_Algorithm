// 7-41 计算阶乘和 (10分)
//对于给定的正整数N，需要你计算 S=1!+2!+3!+...+N!。

//输入格式：
//输入在一行中给出一个不超过10的正整数N。

//输出格式：
//在一行中输出S的值。

//输入样例：
//3
  
//输出样例：
//9

#include <stdio.h>

int factorial(int n) {
    int num = 1;
    for (int i = 1; i <= n; i++)
    {
        num *= i;
    }
    return num;
}

int main() {
    int N;
    scanf("%d", &N);
    int s = 0;
    for (int i = 1; i <= N; i++)
    {
        s += factorial(i);
    }
    printf("%d", s);
}