// 6-15 计算最长的字符串长度 (15分)
//本题要求实现一个函数，用于计算有n个元素的指针数组s中最长的字符串的长度。

//输入样例：
//4
//blue
//yellow
//red
//green

//输出样例：
//6

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXN 10
#define MAXS 20

int max_len( char *s[], int n );

int main()
{
    int i, n;
    char *string[MAXN] = {NULL};

    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        string[i] = (char *)malloc(sizeof(char)*MAXS);
        scanf("%s", string[i]);
    }
    printf("%d\n", max_len(string, n));

    return 0;
}

/* 你的代码将被嵌在这里 */
int max_len(char* s[], int n) {
    int length = strlen(s[0]), temp;
    for (int i = 0; i < n; i++)
    {
        temp = strlen(s[i]);
        if (temp > length) length = temp;
    }
    return length;
}