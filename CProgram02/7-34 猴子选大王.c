// 7-34 猴子选大王 (20分)
//一群猴子要选新猴王。新猴王的选择方法是：让N只候选猴子围成一圈，从某位置起顺序编号为1~N号。从第1号开始报数，每轮从1报到3，凡报到3的猴子即退出圈子，接着又从紧邻的下一只猴子开始同样的报数。如此不断循环，最后剩下的一只猴子就选为猴王。请问是原来第几号猴子当选猴王？

//输入格式：
//输入在一行中给一个正整数N（≤1000）。

//输出格式：
//在一行中输出当选猴王的编号。

//输入样例：
//11

//输出样例：
//7

#include <stdio.h>

int main()
{
	int N, count = 1, index;
	scanf("%d", &N);
	int re = N;
	int mon[N];
	for (int i = 0; i < N; i++)
	{
		mon[i] = 1;
	}
	while (re > 1)
	{
		for (int i = 0; i < N; i++)
		{
			if (mon[i] != 0) {
				if (count % 3 == 0) {
					mon[i] = 0;
					re--;
					if (re == 1) goto END;
				}
				count++;
			}
		}
	}
    END:
	for (int i = 0; i < N; i++)
	{
		if (mon[i] == 1) {
			index = i + 1;
			break;
		}
	}
	printf("%d", index);
}