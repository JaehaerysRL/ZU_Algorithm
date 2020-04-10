// 7-124 上三角数字三角形 (10分)
//输入一个正整数n，输出具有n层的上三角数字三角形。

//输入格式:
//只有一个正整数n，1<=n<=100。

//输出格式:
//一个上三角数字三角形，每个数字占四个字符位置。

//输入样例:
//5

//输出样例:
//   1   2   3   4   5
//   6   7   8   9
//  10  11  12
//  13  14
//  15

#include <stdio.h>
int main() {
	int n, temp, delta;
	scanf("%d", &n);
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if(i+j<=n+1){
			    count++;
			    printf("%4d", count);
			}
		}
		printf("\n");
	}
}