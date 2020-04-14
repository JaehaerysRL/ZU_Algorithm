// 7-52 找最小的字符串 (15分)
//本题要求编写程序，针对输入的N个字符串，输出其中最小的字符串。

//输入格式：
//输入第一行给出正整数N；随后N行，每行给出一个长度小于80的非空字符串，其中不会出现换行符，空格，制表符。

//输出格式：
//在一行中用以下格式输出最小的字符串：
//Min is: 最小字符串

//输入样例：
//5
//Li
//Wang
//Zha
//Jin
//Xian
 
//输出样例：
//Min is: Jin

#include<stdio.h>
#include <string.h>

int main()
{
	int N;
	scanf("%d", &N);
	getchar();
	char min[81];
	for (int i = 0; i < N; i++)
	{
		char tmp[81];
		gets(tmp);
		if (i == 0 || strcmp(min,tmp)>0) {
			strcpy(min, tmp);
		}
	}
	printf("Min is: %s", min);
}