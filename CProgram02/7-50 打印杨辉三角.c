// 7-50 打印杨辉三角 (20分)
//本题要求按照规定格式打印前N行杨辉三角。

//输入格式：
//输入在一行中给出N（1≤N≤10）。

//输出格式：
//以正三角形的格式输出前N行杨辉三角。每个数字占固定4位。

//输入样例：
//6

//输出样例：
//        1
//       1   1
//      1   2   1
//     1   3   3   1
//    1   4   6   4   1
//   1   5  10  10   5   1

#include<stdio.h>

int main()
{
	int N;
	scanf("%d", &N);
	int num[N][N];
	num[0][0] = 1;
	for (int j = 0; j < N - 1; j++)
	{
		printf(" ");
	}
	printf("%4d\n", 1);
	int k = N - 2;
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < k; j++)
		{
			printf(" ");
		}

		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i) {
				num[i][j] = 1;
			}
			else {
				num[i][j] = num[i - 1][j - 1] + num[i - 1][j];
			}
			printf("%4d", num[i][j]);
		}
		printf("\n");
		k--;
	}
}