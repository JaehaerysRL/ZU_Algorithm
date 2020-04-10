// 7-108 将x的平方赋值给y (5分)
//假设x的值为3，计算x的平方并赋值给y，分别以“y = x ∗ x”和“x ∗ x = y”的形式输出x和y的值。

//输出格式：
//按照下列格式输出代入x=3的结果：
//y = x * x
//x * x = y

#include <stdio.h>
int main() {
	int x = 3;
	int y = x * x;
	printf("%d = %d * %d\n", y, x, x);
	printf("%d * %d = %d", x, x, y);
}