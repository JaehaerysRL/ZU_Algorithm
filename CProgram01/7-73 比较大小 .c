// 7-73 比较大小 (10分)
//本题要求将输入的任意3个整数从小到大输出。

//输入格式:
//输入在一行中给出3个整数，其间以空格分隔。

//输出格式:
//在一行中将3个整数从小到大输出，其间以“->”相连。

//输入样例:
//4 2 8

//输出样例:
//2->4->8

#include <stdio.h>
int main() {
	int a, b, c, temp;
	scanf("%d %d %d", &a, &b, &c);
	if (a < b) {
		temp = a;
		a = b;
		b = temp;
	}
	if (a < c) {
		temp = a;
		a = c;
		c = temp;
	}
	if (b < c) {
		temp = b;
		b = c;
		c = temp;
	}
	printf("%d->%d->%d", c, b, a);
}