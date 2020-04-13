// 6-7 移动字母 (10分)
//本题要求编写函数，将输入字符串的前3个字符移到最后。

//输入样例：
//abcdef

//输出样例：
//defabc

#include <stdio.h>
#include <string.h>

#define MAXS 10

void Shift( char s[] );

void GetString( char s[] ); /* 实现细节在此不表 */

int main()
{
    char s[MAXS];

    GetString(s);
    Shift(s);
    printf("%s\n", s);
	
    return 0; 
}

/* 你的代码将被嵌在这里 */
void Shift(char s[]) {
    int n = strlen(s);
    char temp[3] = { 0 };
    int j = 0;
    for (int i = 0; i < 3; i++) temp[i] = s[i];
    for (int i = 0; i < n-3; i++) s[i] = s[i+3];
    for (int i = n-3; i < n; i++) s[i] = temp[j++];
}