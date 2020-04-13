// 6-17 指定位置输出字符串 (20分)
//本题要求实现一个函数，对给定的一个字符串和两个字符，打印出给定字符串中从与第一个字符匹配的位置开始到与第二个字符匹配的位置之间的所有字符。

//输入样例1：
//program
//r g

//输出样例1：
//rog
//rogram

#include <stdio.h>

#define MAXS 10

char *match( char *s, char ch1, char ch2 );

int main()
{
    char str[MAXS], ch_start, ch_end, *p;

    scanf("%s\n", str);
    scanf("%c %c", &ch_start, &ch_end);
    p = match(str, ch_start, ch_end);
    printf("%s\n", p);

    return 0;
}

/* 你的代码将被嵌在这里 */
char* match(char* s, char ch1, char ch2) {
    int n = strlen(s), i;
    char* p = "";
    for (i = 0; i < n; i++)
    {
        if (s[i] == ch1) {
            p = s + i;
            break;
        }
    }
    if (p) {
        for (i; i < n;i++) {
            printf("%c", s[i]);
            if (s[i] == ch2) break;
        }
    }
    printf("\n");
    return p;
}