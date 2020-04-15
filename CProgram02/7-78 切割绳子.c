// 7-78 切割绳子 (5分)
//有N条绳子，它们的长度分别为Li。如果从它们中切割出K条长度相同的绳子，这K条绳子每条最长能有多长？

//输入格式:
//第一行两个整数n和k（1<n<10000; 1<k<10000）。 接下来n行，描述了每条绳子的长度Li，Li也是整数。

//输出格式:
//切割后每条绳子的最大长度。

//输入样例:
//4 11
//802
//743
//457
//539

//输出样例:
//200

#include <stdio.h>

int main()
{
	int n, k, sum = 0, left, right, ave, count;
	scanf("%d %d", &n, &k);
	int Li[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &Li[i]);
		sum += Li[i];
	}
	left = 0;
	right = sum / k;
	while (1)
	{
	    if(right-left<=1) break;
		ave = (left + right) / 2;
		count = 0;
		for (int i = 0; i < n; i++)
		{
			count += Li[i] / ave;
		}
		if (count < k) {
			right = ave;
		}
		else if (count > k) {
			left = ave;
		}
		else {
			break;
		}
	}
	for (int i = ave; i < right; i++)
	{
		count = 0;
		for (int j = 0; j < n; j++)
		{
			count += Li[j] / i;
		}
		if (count < k) break;
		else ave = i;
	}
	printf("%d", ave);
}
