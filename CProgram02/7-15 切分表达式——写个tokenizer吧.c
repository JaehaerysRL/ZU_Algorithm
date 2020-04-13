// 7-15 切分表达式——写个tokenizer吧 (20分)
//[先说点出题背景]
//这个题是为低年级同学、学C语言的同学准备的，因为，对这部分同学，这个题目编写起来略有一点复杂。如果是高年级、学过了正则表达式（Regular Expression）的同学或者学过了Java等OO语言的同学做这个题，应当发现这题比较简单吧。哦，对了，什么是tokenizer？请自行查询解决。反正在此处不应翻译成“令牌解析器”。
//[正题]
//四则运算表达式由运算数（必定包含数字，可能包含正或负符号、小数点）、运算符（包括+、-、*、/）以及小括号（(和)）组成，每个运算数、运算符和括号都是一个token（标记）。现在，对于给定的一个四则运算表达式，请把她的每个token切分出来。题目保证给定的表达式是正确的，不需要做有效性检查。

//输入格式:
//在一行中给出长度不超过40个字符的表达式，其中没有空格，仅由上文中token的字符组成
//输出格式:
//依次输出表达式中的tokens，每个token占一行。

//输入样例:
//32*((2-2)+5)/(-15)
 
//输出样例:
//32
//*
//(
//(
//2
//-
//2
//)
//+
//5
//)
// /
//(
//-15
//)

#include <stdio.h>
#include <string.h>

enum {
	Num, Op, Circle, Point, Other
}flag;


int main()
{
	char s[41];
	gets(s);
	int n = strlen(s);
	flag = Other;
	if (s[0] == '-') {
		flag = Op;
	}
	else if (s[0] == '(') {
		flag = Circle;
	}
	else flag = Num;
	printf("%c", s[0]);
	for (int i = 1; i < n; i++)
	{
		if (flag == Op) {
			if (s[i] >= '0' && s[i] <= '9') {
				flag = Num;
				printf("%c", s[i]);
			}
			else if (s[i] == '(') {
				flag = Circle;
				printf("\n%c", s[i]);
			}
		}
		else if (flag == Num) {
			if (s[i] >= '0' && s[i] <= '9') {
				flag = Num;
				printf("%c", s[i]);
			}
			else if (s[i] == '.') {
				flag = Point;
				printf("%c", s[i]);
			}
			else {
				flag = Other;
				printf("\n%c", s[i]);
			}
		}
		else if (flag == Circle) {
			if (s[i] == '-') {
				flag = Op;
			}
			else if (s[i] == '(') {
				flag = Circle;
			}
			else flag = Num;
			printf("\n%c", s[i]);
		}
		else if (flag == Point) {
			flag = Num;
			printf("%c", s[i]);
		}
		else
		{
			if (s[i] >= '0' && s[i] <= '9') {
				flag = Num;
			}
			else if (s[i] == '(') {
				flag = Circle;
			}
			else {
				flag = Other;
			}
			printf("\n%c", s[i]);
		}
	}
}