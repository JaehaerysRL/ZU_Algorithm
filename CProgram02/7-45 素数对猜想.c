// 7-45 素数对猜想 (20分)
//让我们定义dn为：dn=pn+1−pn，其中pi是第i个素数。显然有d1=1，且对于n>1有dn是偶数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。

//现给定任意正整数N(<10^​5)，请计算不超过N的满足猜想的素数对的个数。

//输入格式:
//输入在一行给出正整数N。

//输出格式:
//在一行中输出不超过N的满足猜想的素数对的个数。

//输入样例:
//20

//输出样例:
//4

#include <stdio.h>
#include <math.h>

int isPrime(int n) {
	int flag = 1;
	for (int i = 3; i <= sqrt(n); i+=2)
	{
		if (n % i == 0) {
			flag = 0;
			break;
		}
	}
	return flag;
}

int main()
{
    int N, count = 0;
    scanf("%d", &N);
	for (int i = 5; i <= N; i+=2)
	{
		if (isPrime(i) == 1) {
			if (isPrime(i - 2) == 1) count++;
		}
	}
	printf("%d", count);
}