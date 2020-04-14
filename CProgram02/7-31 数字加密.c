// 7-31 数字加密 (15分)
//输入一个四位数，将其加密后输出。方法是将该数每一位上的数字加9，然后除以10取余，做为该位上的新数字，最后将千位和十位上的数字互换，百位和个位上的数字互换，组成加密后的新四位数。例如输入1257，经过加9取余后得到新数字0146，再经过两次换位后得到4601。

//输入格式：
//输入在一行中给出一个四位的整数x，即要求被加密的数。

//输出格式：
//在一行中按照格式“The encrypted number is V”输出加密后得到的新数V。

//输入样例：
//1257

//输出样例：
//The encrypted number is 4601

#include <stdio.h>

int tr(int n) {
	return (n+9)%10;
}

int main()
{
	int a, b, c, d;
	scanf("%1d%1d%1d%1d", &a, &b, &c, &d);
	a = tr(a);
	b = tr(b);
	c = tr(c);
	d = tr(d);
	printf("The encrypted number is %d%d%d%d", c, d, a, b);
}