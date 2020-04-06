// 7-2 I Love GPLT (5分)
//这道超级简单的题目没有任何输入。
//你只需要把这句很重要的话 —— I Love GPLT ——竖着输出就可以了。
//所谓“竖着输出”，是指每个字符占一行（包括空格），即每行只能有1个字符和回车。

#include <stdio.h>
#include <string.h>

int main(){
    char str[]= "I Love GPLT";
    for (int i=0;i<strlen(str);i++) {
        printf("%c\n",str[i]);
    }
}