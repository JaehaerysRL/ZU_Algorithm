﻿// 7-54 矩阵A乘以B (15分)
//给定两个矩阵A和B，要求你计算它们的乘积矩阵AB。需要注意的是，只有规模匹配的矩阵才可以相乘。即若A有R​a行、Ca列，B有Rb行、Cb列，则只有Ca与Rb相等时，两个矩阵才能相乘。

//输入格式：
//输入先后给出两个矩阵A和B。对于每个矩阵，首先在一行中给出其行数R和列数C，随后R行，每行给出C个整数，以1个空格分隔，且行首尾没有多余的空格。输入保证两个矩阵的R和C都是正数，并且所有整数的绝对值不超过100。

//输出格式：
//若输入的两个矩阵的规模是匹配的，则按照输入的格式输出乘积矩阵AB，否则输出Error: Ca != Rb，其中Ca是A的列数，Rb是B的行数。

//输入样例1：
//2 3
//1 2 3
//4 5 6
//3 4
//7 8 9 0
//-1 -2 -3 -4
//5 6 7 8

//输出样例1：
//2 4
//20 22 24 16
//53 58 63 28

#include <stdio.h>

int main()
{
	int r1, c1, r2, c2;
	scanf("%d %d", &r1, &c1);
	int recA[r1][c1];
	for (int i = 0; i < r1; i++)
	{
		for (int j = 0; j < c1; j++)
		{
			scanf("%d", &recA[i][j]);
		}
	}
	scanf("%d %d", &r2, &c2);
	int recB[r2][c2];
	for (int i = 0; i < r2; i++)
	{
		for (int j = 0; j < c2; j++)
		{
			scanf("%d", &recB[i][j]);
		}
	}
	if (c1 != r2) {
		printf("Error: %d != %d", c1, r2);
	}
	else {
	    printf("%d %d\n", r1, c2);
		for (int i = 0; i < r1; i++)
		{
			for (int j = 0; j < c2; j++)
			{
				int num = 0;
				for (int k = 0; k < c1; k++)
				{
					num += recA[i][k] * recB[k][j];
				}
				if (j != c2 - 1) printf("%d ",num);
				else printf("%d\n",num);
			}
		}
	}
}
