// 7-46 找出不是两个数组共有的元素 (20分)
//给定两个整型数组，本题要求找出不是两者共有的元素。

//输入格式:
//输入分别在两行中给出两个整型数组，每行先给出正整数N（≤20），随后是N个整数，其间以空格分隔。

//输出格式:
//在一行中按照数字给出的顺序输出不是两数组共有的元素，数字间以空格分隔，但行末不得有多余的空格。题目保证至少存在一个这样的数字。同一数字不重复输出。

//输入样例:
//10 3 -5 2 8 0 3 5 -15 9 100
//11 6 4 8 2 6 -5 9 0 100 8 1

//输出样例:
//3 5 -15 6 4 1

#include <stdio.h>

int main()
{
	int n1, n2, c = 0, sig = 0;
	int s1[21], s2[21], co[21];
	scanf("%d", &n1);
	for (int i = 0; i < n1; i++)
	{
		scanf("%d", &s1[i]);
	}
	scanf("%d", &n2);
	for (int j = 0; j < n2; j++)
	{
		scanf("%d", &s2[j]);
		for (int i = 0; i < n1; i++)
		{
			if (s2[j] == s1[i]) {
				if (c == 0) co[c++] = s2[j];
				else {
					sig = 0;
					for (int k = 0; k < c; k++)
					{
						if (co[k] == s2[j]) {
							sig = 1;
							break;
						}
					}
					if (sig == 0)co[c++] = s2[j];
				}
			}
		}
	}
	//以上找出了相同元素，以下开始过滤不同的，开始看错题写反了
	int imco[21], ic = 0;
	for (int i = 0; i < n1; i++)
	{
		int sig = 1;//默认打印
		for (int k = 0; k < c; k++)
		{
			if (co[k] == s1[i]) {
				sig = 0;
				break;
			}
		}
		for (int k = 0; k < ic; k++)
		{
			if (imco[k] == s1[i]) {
				sig = 0;
				break;
			}
		}
		if (sig == 1)imco[ic++] = s1[i];
	}
	for (int j = 0; j < n2; j++)
	{
		int sig = 1;//默认打印
		for (int k = 0; k < c; k++)
		{
			if (co[k] == s2[j]) {
				sig = 0;
				break;
			}
		}
		for (int k = 0; k < ic; k++)
		{
			if (imco[k] == s2[j]) {
				sig = 0;
				break;
			}
		}
		if (sig == 1)imco[ic++] = s2[j];
	}
	printf("%d", imco[0]);
	if (ic > 1) {
		for (int i = 1; i < ic; i++)
		{
			printf(" %d", imco[i]);
		}
	}
}
