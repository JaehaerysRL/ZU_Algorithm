// 6-20 strcmp (30分)
//Implement the strcmp() as in the standard library.

//输入样例：
//hello hello

//输出样例：
//0

#include <stdio.h>

int mycmp( const char* s1, const char* s2 );

int main()
{

  char s1[80], s2[80];

  scanf("%s %s", s1, s2);

  printf("%d", mycmp(s1,s2));

  return 0;

}

/* 请在这里填写答案 */
int mycmp(const char* s1, const char* s2) {
    int sum = 0, i = 0;
    while (s1[i]!='\0' || s2[i] != '\0')
    {
        sum += s1[i] - s2[i];
        i++;
    }
    return sum;
}