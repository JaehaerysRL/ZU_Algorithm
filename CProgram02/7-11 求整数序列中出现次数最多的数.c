// 7-11 求整数序列中出现次数最多的数 (15分)
//本题要求统计一个整型序列中出现次数最多的整数及其出现次数。

//输入格式：
//输入在一行中给出序列中整数个数N（0<N≤1000），以及N个整数。数字间以空格分隔。

//输出格式：
//在一行中输出出现次数最多的整数及其出现次数，数字间以空格分隔。题目保证这样的数字是唯一的。

//输入样例：
//10 3 2 -1 5 3 4 3 0 3 2

//输出样例：
//3 4

#include <stdio.h>

int main()
{
	int n, flag;
	scanf("%d", &n);
	if (n == 0) {
		printf("0 0");
		return 0;
	}
	int num[n];
	int freq[n][2];
	scanf("%d", &num[0]);
	int len = 1;
	freq[0][0] = num[0];
	freq[0][1] = 1;
	for (int i = 1; i < n; i++)
	{
		scanf("%d", &num[i]);
		flag = 0;
		for (int j = 0; j < len; j++)
		{
			if (freq[j][0] == num[i]) {
				freq[j][1]++;
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			freq[len][0] = num[i];
			freq[len][1] = 1;
			len++;
		}
	}
	int most = freq[0][0];
	int max = freq[0][1];
	for (int i = 1; i < len; i++)
	{
		if (freq[i][1] > max) {
			most = freq[i][0];
			max = freq[i][1];
		}
	}
	printf("%d %d", most,max);
}