﻿// 7-97 计算个人所得税 (10分)
//假设个人所得税为：税率×(工资−1600)。请编写程序计算应缴的所得税，其中税率定义为：

//当工资不超过1600时，税率为0；当工资在区间(1600, 2500]时，税率为5%；当工资在区间(2500, 3500]时，税率为10%；当工资在区间(3500, 4500]时，税率为15%；当工资超过4500时，税率为20%。
//输入格式:
//输入在一行中给出非负工资。

//输出格式:
//在一行输出个人所得税，精确到小数点后2位。

//输入样例1:
//1600

//输出样例1:
//0.00

#include <stdio.h>
int main()
{
	double s, t = 0;
	scanf("%lf", &s);
	if (s > 1600 && s <= 2500)t = 0.05 * (s - 1600);
	else if (s > 2500 && s <= 3500)t = 0.10 * (s - 1600);
	else if (s > 3500 && s <= 4500)t = 0.15 * (s - 1600);
	else if (s > 4500)t = 0.20 * (s - 1600);
	printf("%.2lf", t);
}