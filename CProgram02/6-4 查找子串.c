// 6-4 查找子串 (20分)
//本题要求实现一个字符串查找的简单函数。
//函数search在字符串s中查找子串t，返回子串t在s中的首地址。若未找到，则返回NULL。

//输入样例1：
//The C Programming Language
//ram

//输出样例1：
//10

#include <stdio.h>
#define MAXS 30

char *search(char *s, char *t);
void ReadString( char s[] ); /* 裁判提供，细节不表 */

int main()
{
    char s[MAXS], t[MAXS], *pos;

    ReadString(s);
    ReadString(t);
    pos = search(s, t);
    if ( pos != NULL )
        printf("%d\n", pos - s);
    else
        printf("-1\n");

    return 0;
}

/* 你的代码将被嵌在这里 */
char* search(char* s, char* t) {
    int n = strlen(s);
    int m = strlen(t);
    char* r = NULL;
    int count, i, j, k;
    for (i = 0; i <= n-m; i++)
    {
        count = 0;
        k = i;
        for (j = 0; j <= m; j++)
        {
            if (s[k++] == t[j]) {
                count++;
                if (count == m) {
                    r = &s[i];
                    goto END;
                }
            }
            else break;
        }
    }
END: return r;
}