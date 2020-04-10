// 7-121 作品评分 (10分)
//全国中小学生Scratch作品大赛拉开了序幕。每个参赛选手可以通过网络直接上传作品。本次比赛人人可做评委。每个网络评委可以通过网络对每一件作品进行打分。评分系统也是请程序高手设计的，能自动去掉一个最高分和一个最低分，求出平均分。

//输入格式:
//输入数据包括两行: 第一行为n，表示n个评委，n>2。 第二行是n个评委的打分，分数之间有一个空格。打分是可以带有小数部分的。

//输出格式:
//输出平均分，结果保留两位小数。

//输入样例:
//6
//10 9 8 7.9 9 9.5

//输出样例:
//8.88

#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	float grade[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%f", &grade[i]);
	}
	float max, min, sum;
	sum = max = min = grade[0];
	for (int i = 1; i < n; i++)
	{
		if (grade[i] > max) max = grade[i];
		if (grade[i] < min) min = grade[i];
		sum += grade[i];
	}
	sum = sum - max - min;
	sum = sum / (n - 2);
	printf("%.2f", sum);
}