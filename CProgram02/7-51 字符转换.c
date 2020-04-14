// 7-51 字符转换 (15分)
//本题要求提取一个字符串中的所有数字字符（'0'……'9'），将其转换为一个整数输出。

//输入格式：
//输入在一行中给出一个不超过80个字符且以回车结束的字符串。

//输出格式：
//在一行中输出转换后的整数。题目保证输出不超过长整型范围。

//输入样例：
//free82jeep5

//输出样例：
//825

#include<stdio.h>
#include <string.h>

int main()
{
	char s[81];
	gets(s);
	int n = strlen(s), count = 0,sig = 0;
	for (int i = 0; i < n; i++)
	{
	    if(s[i] == '0' && count == 0){
		    sig = 1;
	    }else if (s[i] >= 48 && s[i] <= 57) {
			if (count != 0 || s[i] != '0') {
				count++;
				printf("%c", s[i]);
			}
		}else if(s[i] == '-' && count == 0){
		    printf("%c", s[i]);
		}
	}
	if(sig == 1 && count == 0) printf("%c",'0');
}