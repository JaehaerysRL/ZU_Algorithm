// 6-10 使用函数实现字符串部分复制 (20分)
//本题要求编写函数，将输入字符串t中从第m个字符开始的全部字符复制到字符串s中。

//输入样例：
//7
//happy new year

//输出样例：
//new year

#include <stdio.h>
#define MAXN 20

void strmcpy( char *t, int m, char *s );
void ReadString( char s[] ); /* 由裁判实现，略去不表 */

int main()
{
    char t[MAXN], s[MAXN];
    int m;

    scanf("%d\n", &m);
    ReadString(t);
    strmcpy( t, m, s );
    printf("%s\n", s);

    return 0;
}

/* 你的代码将被嵌在这里 */
void strmcpy(char* t, int m, char* s) {
    int n = strlen(t);
    if (m > n) *s = NULL;
    else {
        int j = 0;
        for (int i = m-1; i < n; i++)
        {
            s[j++] = t[i];
        }
    }
}