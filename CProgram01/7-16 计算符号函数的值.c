// 7-16 计算符号函数的值 (10分)
//对于任一整数n，符号函数sign(n)
//请编写程序计算该函数对任一输入整数的值。

//输入格式:
//输入在一行中给出整数n。

//输出格式:
//在一行中按照格式“sign(n) = 函数值”输出该整数n对应的函数

#include <stdio.h>

int main()
{
	int a;
	scanf("%d", &a);
	if (a < 0) printf("sign(%d) = %d", a ,-1);
	else if (a > 0) printf("sign(%d) = %d", a, 1);
	else printf("sign(%d) = %d", a, 0);
}