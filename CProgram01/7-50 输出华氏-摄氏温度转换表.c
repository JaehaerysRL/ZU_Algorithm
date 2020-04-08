// 7-50 输出华氏-摄氏温度转换表 (15分)
//输入2个正整数lower和upper（lower≤upper≤100），请输出一张取值范围为[lower，upper]、且每次增加2华氏度的华氏-摄氏温度转换表。
//温度转换的计算公式：C=5×(F−32)/9，其中：C表示摄氏温度，F表示华氏温度。

//输入格式:
//在一行中输入2个整数，分别表示lower和upper的值，中间用空格分开。

//输出格式:
//第一行输出："fahr celsius"

//接着每行输出一个华氏温度fahr（整型）与一个摄氏温度celsius（占据6个字符宽度，靠右对齐，保留1位小数）。

//若输入的范围不合法，则输出"Invalid."。

//输入样例1:
//32 35

      
    
//输出样例1:
//fahr celsius
//32   0.0
//34   1.1

#include <stdio.h>
void fc(int f) {
	double c;
	c = (double) 5 * (f - 32) / (double)9;
	printf("%d%6.1lf\n", f, c);
}
int main() {
	int l, u;
	scanf("%d %d", &l, &u);
	if (l <= u && u <= 100) {
        printf("fahr celsius\n");
		for (int i = l; i <= u; i += 2)
		{
			fc(i);
		}
	}
	else {
		printf("Invalid.");
	}
}