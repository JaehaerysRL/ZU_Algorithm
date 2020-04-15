// 7-77 御膳房 (5分)
//御膳房要准备皇帝的早餐，非常的辛苦。辛苦是因为这个皇帝很挑剔，要求相邻两天不能吃相同的早餐。根据采买到的原料，御膳房准备了未来几天的早餐的菜单。但是厨师不懂数学，排出的菜单有相邻两天重复的。你能否根据菜单，判断能不能调整成相邻两天不重复的呢？

//输入格式:
//首先是一个正整数N（1<N<100），表示厨师准备了N天的菜单。 然后是N个正整数Pi（1<Pi<100），每个数字表示一天的早餐内容。相同的数字表示相同的内容。

//输出格式:
//如果可以调整成相邻两天不重复，就输出
//YES否则就输出NO
//输入样例:
//6
//1 2 4 6 6 4

//输出样例:
//YES

#include <stdio.h>

int main()
{
	int N, t;
	scanf("%d", &N);
	int dinner[100] = { 0 };
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &t);
		dinner[t]++;
	}
	int max = dinner[0];
	for (int i = 1; i < N; i++)
	{
		if (dinner[i] > max)max = dinner[i];
	}
	int judge = N / 2 + N % 2;
	if (max > judge)printf("NO");
	else printf("YES");
}
