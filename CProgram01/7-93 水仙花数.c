// 7-93 水仙花数 (20分)
//水仙花数是指一个N位正整数（N≥3），它的每个位上的数字的N次幂之和等于它本身。例如：153=1^3+5^3^+3^3。 本题要求编写程序,计算所有N位水仙花数。

//输入格式:
//输入在一行中给出一个正整数N（3≤N≤7）。

//输出格式:
//按递增顺序输出所有N位水仙花数，每个数字占一行。

//输入样例:
//3
  
//输出样例:
//153
//370
//371
//407

#include <stdio.h>
int pow(int a, int b)
{
	int s = 1;
	for (int i = 1;i <= b;i++)
		s = s * a;
	return s;
}

int main()
{
	int N, sum, temp, flag;
	scanf("%d", &N);
	for (int n = pow(10, N - 1); n < pow(10, N); n++)
	{
		temp = n;
		sum = 0;
		flag = 0;
		for (int i = 1; i <= N; i++)
		{
			sum += pow(temp % 10, N);
			temp /= 10;
			if (sum >= n && i < N) {
				flag = 1;
				break;
			}
		}
		if (sum == n && flag == 0)printf("%d\n", n);
	}
}