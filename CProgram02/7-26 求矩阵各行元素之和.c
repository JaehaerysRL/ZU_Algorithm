// 7-26 求矩阵各行元素之和 (15分)
//本题要求编写程序，求一个给定的m×n矩阵各行元素之和。

//输入格式：
//输入第一行给出两个正整数m和n（1≤m,n≤6）。随后m行，每行给出n个整数，其间以空格分隔。

//输出格式：
//每行输出对应矩阵行元素之和。
//输入样例：
//3 2
//6 3
//1 -8
//3 12

//输出样例：
//9
//-7
//15

#include <stdio.h>
#include <string.h>

int main()
{
	int m, n;
	scanf("%d %d", &m, &n);
	for (int i = 0; i < m; i++)
	{
		int sum = 0, temp;
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &temp);
			sum += temp;
		}
		printf("%d\n", sum);
	}
}

