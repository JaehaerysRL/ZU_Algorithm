// 7-1 重要的话说三遍 (5分)
//这7-30 输出学生成绩 (20分)
//本题要求编写程序，根据输入学生的成绩，统计并输出学生的平均成绩、最高成绩和最低成绩。建议使用动态内存分配来实现。

//输入格式：
//输入第一行首先给出一个正整数N，表示学生的个数。接下来一行给出N个学生的成绩，数字间以空格分隔。

//输出格式：
//按照以下格式输出：
//average = 平均成绩
//max = 最高成绩
//min = 最低成绩
//结果均保留两位小数。

//输入样例：
//3
//85 90 95
 
//输出样例：
//average = 90.00
//max = 95.00
//min = 85.00

#include <stdio.h>

int main()
{
	int N;
	double max, min, sum = 0, ave, tmp;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%lf", &tmp);
		sum += tmp;
		if (i == 0) {
			max = tmp;
			min = tmp;
		}
		else {
			if (tmp > max)max = tmp;
			else if (tmp < min)min = tmp;
		}
	}
	ave = sum / (double)N;
	printf("average = %.2lf\nmax = %.2lf\nmin = %.2lf", ave, max, min);
}