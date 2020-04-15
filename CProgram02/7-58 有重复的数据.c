// 7-58 有重复的数据 (10分)
//在一大堆数据中找出重复的是一件经常要做的事情。现在，我们要处理许多整数，在这些整数中，可能存在重复的数据。

//你要写一个程序来做这件事情，读入数据，检查是否有重复的数据。如果有，输出“YES”这三个字母；如果没有，则输出“NO”。

//输入格式:
//你的程序首先会读到一个正整数n，1<=n<=100000。然后是n个整数。

//输出格式:
//如果这些整数中存在重复的，就输出：
//YES
//否则，就输出：
//NO

//输入样例:
//5
//1 2 3 1 4

//输出样例:
//YES

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}

int main()
{
	int N;
	scanf("%d", &N);
	if (N <= 1) {
		printf("NO");
		return 0;
	}
	int num[N];
	for (int i = 1; i < N; i++)
	{
		scanf("%d", &num[i]);
	}

	qsort(num, N, sizeof(int),cmp);

	int i;
	for (i = 1; i < N; i+=2)
	{
		if (num[i] == num[i - 1] || num[i] == num[i + 1])break;
	}
	if (i<N) printf("YES");
	else printf("NO");
}