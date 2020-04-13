// 6-19 strlen (10分)
//Implement the strcmp() as in the standard library.

//输入样例：
//hello

//输出样例：
//5

#include <stdio.h>

int mylen( const char *s );

int main()
{
  char word[80];
  scanf("%s", word);

  printf("%d", mylen(word));

  return 0;

}

/* 请在这里填写答案 */
int mylen(const char* s) {
    int n = 0, i = 0;
    while (s[i++]!='\0') n++;
    return n;
}