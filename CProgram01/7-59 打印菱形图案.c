// 7-59 打印菱形图案 (15分)
//本题要求编写程序，打印一个高度为n的、由“*”组成的正菱形图案。

//输入格式:
//输入在一行中给出一个正的奇数n。

//输出格式:
//输出由n行星号“*”组成的菱形，如样例所示。每个星号后跟一个空格。

//输入样例:
//7
 
//输出样例:
//      * 
//    * * * 
//  * * * * * 
//* * * * * * * 
//  * * * * * 
//    * * * 
//      * 

#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	int m = n / 2 + 1;
	int c = 1;
	for (int i = 1; i <= n; i++)
	{
		if (i<=m)
		{
			for (int j = 1; j <= m - i; j++) printf("  ");
			for (int j = 1; j <= 2*i-1; j++) printf("* ");
		}
		else {
			for (int j = i - m; j >= 1; j--) printf("  ");
			for (int j = 2*n+1-2*i; j >= 1; j--) printf("* ");
		}
		printf("\n");
	}
}