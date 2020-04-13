// 6-16 字符串的连接 (15分)
//本题要求实现一个函数，将两个字符串连接起来。

//输入样例：
//abc
//def

//输出样例：
//abcdef
//abcdef

#include <stdio.h>
#include <string.h>

#define MAXS 10

char *str_cat( char *s, char *t );

int main()
{
    char *p;
    char str1[MAXS+MAXS] = {'\0'}, str2[MAXS] = {'\0'};

    scanf("%s%s", str1, str2);
    p = str_cat(str1, str2);
    printf("%s\n%s\n", p, str1);

    return 0;
}

/* 你的代码将被嵌在这里 */
char* str_cat(char* s, char* t) {
    int nt = strlen(t), ns = strlen(s);
    for (int i = 0; i < nt; i++)
    {
        s[ns + i] = t[i];
    }
    return s;
}