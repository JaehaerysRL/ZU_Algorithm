// 6-1 计算两个复数之积 (15分)
//本题要求实现一个计算复数之积的简单函数。。
//输入样例：
//3 4 5 6

//输出样例：
//(3+4i) * (5+6i) = -9 + 38i

#include <stdio.h>

struct complex{
    int real;
    int imag;
};

struct complex multiply(struct complex x, struct complex y);

int main()
{
    struct complex product, x, y;

    scanf("%d%d%d%d", &x.real, &x.imag, &y.real, &y.imag);
    product = multiply(x, y);
    printf("(%d+%di) * (%d+%di) = %d + %di\n", 
            x.real, x.imag, y.real, y.imag, product.real, product.imag);

    return 0;
}

/* 你的代码将被嵌在这里 */
struct complex multiply(struct complex x, struct complex y) {
    struct complex a;
    a.real = x.real * y.real - x.imag * y.imag;
    a.imag = x.real * y.imag + x.imag * y.real;
    return a;
}