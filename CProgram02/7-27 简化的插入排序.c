// 7-27 简化的插入排序 (15分)
//本题要求编写程序，将一个给定的整数插到原本有序的整数序列中，使结果序列仍然有序。

//输入格式：
//输入在第一行先给出非负整数N（<10）；第二行给出N个从小到大排好顺序的整数；第三行给出一个整数X。

//输出格式：
//在一行内输出将X插入后仍然从小到大有序的整数序列，每个数字后面有一个空格。

//输入样例：
//5
//1 2 4 5 7
//3

//输出样例：
//1 2 3 4 5 7 

#include <stdio.h>
#include <string.h>

int main()
{
	int N, X;
	scanf("%d", &N);
    int num[N + 2];
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &X);
		num[i] = X;
	}
	scanf("%d", &X);
	if (N == 0) num[0] = X;
	int flag = 0;
	for (int i = 0; i < N; i++)
	{
		if (num[i] >= X) {
			for (int j = N; j > i; j--)
			{
				num[j] = num[j - 1];
			}
			num[i] = X;
			flag = 1;
			break;
		}
	}
	if (flag == 0)num[N] = X;
	for (int i = 0; i <= N; i++)
	{
		printf("%d ", num[i]);
	}
}
