// 7-5 输出倒三角图案 (5分)
//本题要求编写程序，输出指定的由“*”组成的倒三角图案。
//* * * *
// * * *
//  * *
//   *
#include <stdio.h>

int main()
{
	for (int i = 4; i > 0; i--)
	{
		for (int j = 0; j < 4-i; j++)
		{
			printf(" ");
		}
		for (int j = 0; j < i-1 ; j++)
		{
			printf("* ");
		}
		printf("*\n");
	}
}