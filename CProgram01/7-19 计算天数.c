// 7-19 计算天数 (15分)
//本题要求编写程序计算某年某月某日是该年中的第几天。

//输入格式:
//输入在一行中按照格式“yyyy/mm/dd”（即“年/月/日”）给出日期。注意：闰年的判别条件是该年年份能被4整除但不能被100整除、或者能被400整除。闰年的2月有29天。

//输出格式:
//在一行输出日期是该年中的第几天。

//输入样例1:
//2009/03/02
  
//输出样例1:
//61

#include <stdio.h>

int main()
{
	int y, m, d, l = 28;
	scanf("%d/%d/%d", &y, &m, &d);
	if (y % 400 == 0 || y % 4 == 0 && y % 100 != 0) l = 29;
	switch (m)
	{
	case 2:
		d += 31;
		break;
	case 3:
	case 4:
		d += 31 * (m - 2) + l;
		break;
	case 5:
	case 6:
		d += 31 * (m - 2) + l - 1;
		break;
	case 7:
	case 8:
	case 9:
		d += 31 * (m - 2) + l - 2;
		break;
	case 10:
	case 11:
		d += 31 * (m - 2) + l - 3;
		break;
	case 12:
		d += 31 * (m - 2) + l - 4;
		break;
	default:
		break;
	}
	printf("%d", d);
}