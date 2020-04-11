// 7-6 计算平均成绩 (15分)
//给定N个学生的基本信息，包括学号（由5个数字组成的字符串）、姓名（长度小于10的不包含空白字符的非空字符串）和成绩（[0,100]区间内的整数），要求计算他们的平均成绩，并顺序输出平均线以下的学生名单。

//输入格式：
//输入在一行中给出正整数N（≤10）。随后N行，每行给出一位学生的信息，格式为“学号 姓名 成绩”，中间以空格分隔。
//输出格式：
//首先在一行中输出平均成绩，保留2位小数。然后按照输入顺序，每行输出一位平均线以下的学生的姓名和学号，间隔一个空格。

//输入样例：
//5
//00001 zhang 70
//00002 wang 80
//00003 qian 90
//10001 li 100
//21987 chen 60

//输出样例：
//80.00
//zhang 00001
//chen 21987

#include<stdio.h>
#include<string.h>

struct student //构造学生结构体，即构造struct student这种数据类型
{
	char id[6];    //学号，由于题目要求五个数字组成的字符串所以需要申请足够的内存空间
	char name[11]; //姓名
	float score;   //成绩
};

int main()
{
	struct student stu[10]; //定义结构体数组，用于存储每一个学生的学号、姓名、成绩
	int i, N;
	float sum = 0, average;
	scanf("%d\n", &N);
	for (i = 0; i < N; i++) //循环读入学生信息
	{
		scanf("%s%s%f", &stu[i].id, &stu[i].name, &stu[i].score);
		sum += stu[i].score;
	}
	average = sum / N;
	printf("%.2f\n", average);
	for (i = 0; i < N; i++)  //对学生成绩进行处理
	{
		if (stu[i].score < average)
		{
			printf("%s %s\n", stu[i].name, stu[i].id);
		}
	}
	return 0;
}
