// 7-21 螺旋方阵 (20分)
//所谓“螺旋方阵”，是指对任意给定的N，将1到N×N的数字从左上角第1个格子开始，按顺时针螺旋方向顺序填入N×N的方阵里。本题要求构造这样的螺旋方阵。

//输入格式：
//输入在一行中给出一个正整数N（<10）。

//输出格式：
//输出N×N的螺旋方阵。每行N个数字，每个数字占3位。

//输入样例：
//5

//输出样例：
//  1  2  3  4  5
// 16 17 18 19  6
// 15 24 25 20  7
// 14 23 22 21  8
// 13 12 11 10  9

#include <stdio.h>
#include <string.h>

int main()
{
	int N;
	scanf("%d", &N);
	int num[N][N];
	int sig[N][N];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			sig[i][j]=0;
		}
	}
	int count = 0, tmp = 1, i = 0, j = 0;
	//输入，以sig矩阵标记
	while (count < N * N) {
		while (j < N && sig[i][j] == 0) {
			num[i][j] = tmp;
			sig[i][j] = 1;
			tmp++;j++;count++;
		}
		i++;j--;
		while (i < N && sig[i][j] == 0) {
			num[i][j] = tmp;
			sig[i][j] = 1;
			tmp++;i++;count++;
		}
		i--;j--;
		while (j >= 0 && sig[i][j] == 0) {
			num[i][j] = tmp;
			sig[i][j] = 1;
			tmp++;j--;count++;
		}
		i--;j++;
		while (i >= 0 && sig[i][j] == 0) {
			num[i][j] = tmp;
			sig[i][j] = 1;
			tmp++;i--;count++;
		}
		i++;j++;
	}
	//输出
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%3d", num[i][j]);
		}
		printf("\n");
	}
}
