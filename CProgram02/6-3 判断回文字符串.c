// 6-3 判断回文字符串 (20分)
//本题要求编写函数，判断给定的一串字符是否为“回文”。所谓“回文”是指顺读和倒读都一样的字符串。如“XYZYX”和“xyzzyx”都是回文。

//输入样例1：
//thisistrueurtsisiht

//输出样例1：
//Yes
//thisistrueurtsisiht

#include <stdio.h>
#include <string.h>

#define MAXN 20
typedef enum {false, true} bool;

bool palindrome( char *s );

int main()
{
    char s[MAXN];

    scanf("%s", s);
    if ( palindrome(s)==true )
        printf("Yes\n");
    else
        printf("No\n");
    printf("%s\n", s);

    return 0;
}

/* 你的代码将被嵌在这里 */
bool palindrome(char* s) {
    int n = strlen(s);
    char* head = s;
    char* tail = s + n - 1;
    bool judge = true;
    for (int i = 0; i <= n/2; i++)
    {
        if (*head != *tail) {
            judge = false;
            break;
        }
        else {
            head++;
            tail--;
        }
    }
    return judge;
}
