// 7-28 求整数的位数及各位数字之和 (15分)
//对于给定的正整数N，求它的位数及其各位数字之和。

//输入格式：
//输入在一行中给出一个不超过10^9的正整数N。

//输出格式：
//在一行中输出N的位数及其各位数字之和，中间用一个空格隔开。

//输入样例：
//321
   
//输出样例：
//3 6

#include <stdio.h>
#include <math.h>

int main()
{
	int N, sum = 0, bit = 0, temp = 0;
	scanf("%d",&N);
	if (N == 0) bit = 1;
	else {
		bit = log10(N) + 1;
		for (int i = 0; i < bit; i++)
		{
			temp = N % 10;
			sum += temp;
			N = (N - temp) / 10;
		}
	}
	printf("%d %d", bit, sum);
}