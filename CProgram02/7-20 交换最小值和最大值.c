// 7-20 交换最小值和最大值 (15分)
//本题要求编写程序，先将输入的一系列整数中的最小值与第一个数交换，然后将最大值与最后一个数交换，最后输出交换后的序列。

//注意：题目保证最大和最小值都是唯一的。
//输入格式：
//输入在第一行中给出一个正整数N（≤10），第二行给出N个整数，数字间以空格分隔。

//输出格式：
//在一行中顺序输出交换后的序列，每个整数后跟一个空格。

//输入样例：
//5
//8 2 5 1 4

//输出样例：
//1 2 5 4 8 

#include <stdio.h>
#include <string.h>

int main()
{
	int N;
	scanf("%d", &N);
	int num[N];
	scanf("%d", &num[0]);
	int maxIndex = 0, minIndex = 0, max = num[0], min = num[0];
	for (int i = 1; i < N; i++)
	{
		scanf("%d", &num[i]);
		if (num[i] > max) {
			maxIndex = i;
			max = num[i];
		}
		else if (num[i] < min) {
			minIndex = i;
			min = num[i];
		}
	}
	num[minIndex] = num[0];
	num[0] = min;
	if(maxIndex==0){
	    maxIndex=minIndex;
	}
	num[maxIndex] = num[N-1];
	num[N-1] = max;
	for (int i = 0; i < N; i++)
	{
		printf("%d ", num[i]);
	}
}
