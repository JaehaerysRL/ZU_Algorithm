// 7-77 求1到100的和 (10分)
//本题要求编写程序，计算表达式 1 + 2 + 3 + ... + 100 的值。

//输出格式：
//按照以下格式输出：

//sum = 累加和

#include <stdio.h>
int main() {
	int s = 0;
	for (int i = 1; i <= 100; i++)
	{
		s += i;
	}
	printf("sum = %d", s);
}