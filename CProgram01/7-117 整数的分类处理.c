// 7-117 整数的分类处理 (20分)
//给定 N 个正整数，要求你从中得到下列三种计算结果：

//A1 = 能被 3 整除的最大整数
//A2 = 存在整数 K 使之可以表示为 3K+1 的整数的个数
//A3 = 存在整数 K 使之可以表示为 3K+2 的所有整数的平均值（精确到小数点后 1 位）
//输入格式：
//输入首先在第一行给出一个正整数 N，随后一行给出 N 个正整数。所有数字都不超过 100，同行数字以空格分隔。

//输出格式：
//在一行中顺序输出 A1、A2、A3的值，其间以 1 个空格分隔。如果某个数字不存在，则对应输出NONE。

//输入样例 1：
//8
//5 8 7 6 9 1 3 10

//输出样例 1：
//9 3 6.5

#include <stdio.h>
int main()
{
	int n, a1, a2 = 0, flag1 = 0, flag2 = 0, flag3 = 0, k = 0, sum = 0;
	double a3;
	scanf("%d", &n);
	int num[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
	}

	for (int i = 0; i < n; i++)
	{
		if (num[i] % 3 == 0) {
			if (flag1 == 0) {
				a1 = num[i];
				flag1 = 1;
			}
			else {
				if (a1 < num[i])a1 = num[i];
			}
		}
		else if (num[i] % 3 == 1) {
			if (flag2 == 0) {
				a2 = 1;
				flag2 = 1;
			}
			else a2++;
		}
		else {
			if (flag3 == 0) {
				k++;
				sum += num[i];
				flag3 = 1;
			}
			else {
				k++;
				sum += num[i];
			}
		}
	}
	if (flag1 == 0) printf("NONE ");
	else printf("%d ", a1);
	if (flag2 == 0) printf("NONE ");
	else printf("%d ", a2);
	if (flag3 == 0) printf("NONE");
	else {
		a3 = (double)sum / k;
		printf("%.1lf", a3);
	} 
}