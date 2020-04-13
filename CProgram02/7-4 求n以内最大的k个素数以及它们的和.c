// 7-4 求n以内最大的k个素数以及它们的和 (20分)
//本题要求计算并输出不超过n的最大的k个素数以及它们的和。

//输入格式:
//输入在一行中给出n(10≤n≤10000)和k(1≤k≤10)的值。

//输出格式:
//在一行中按下列格式输出:
//素数1+素数2+…+素数k=总和值 
//其中素数按递减顺序输出。若n以内不够k个素数，则按实际个数输出。

//输入样例1:
//1000 10

//输出样例1:
//997+991+983+977+971+967+953+947+941+937=9664

#include <stdio.h>
#include <math.h>

int isPrime(int n) {
	int judge = 1;
	if (n % 2 == 0 && n != 2) judge = 0;
	else {
		for (int i = 3; i <= sqrt(n); i=i+2)
		{
			if (n % i == 0) judge = 0;
		}
	}
	return judge;
}

int main()
{
	int n, k, sum = 0, count = 0;
	scanf("%d %d", &n, &k);
	for (int i = n; i > 1; i--)
	{
		if (isPrime(i) == 1) {
			if (count == 0) {
				printf("%d", i);
			}
			else printf("+%d", i);
			count++;
			sum += i;
		}
		if (count >= k) break;
	}
	printf("=%d", sum);
}