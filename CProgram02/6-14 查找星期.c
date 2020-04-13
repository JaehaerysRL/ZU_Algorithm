// 6-14 查找星期 (15分)
//本题要求实现函数，可以根据下表查找到星期，返回对应的序号。
//序号	星期
//0	Sunday
//1	Monday
//2	Tuesday
//3	Wednesday
//4	Thursday
//5	Friday
//6	Saturday

//输入样例1：
//Tuesday

//输出样例1：
//2

#include <stdio.h>
#include <string.h>

#define MAXS 80

int getindex( char *s );

int main()
{
    int n;
    char s[MAXS];

    scanf("%s", s);
    n = getindex(s);
    if ( n==-1 ) printf("wrong input!\n");
    else printf("%d\n", n);

    return 0;
}

/* 你的代码将被嵌在这里 */
int getindex(char* s) {
    int n;
    if (!strcmp(s, "Monday")) n = 1;
    else if (!strcmp(s, "Tuesday")) n = 2;
    else if (!strcmp(s, "Wednesday")) n = 3;
    else if (!strcmp(s, "Thursday")) n = 4;
    else if (!strcmp(s, "Friday")) n = 5;
    else if (!strcmp(s, "Saturday")) n = 6;
    else if (!strcmp(s, "Sunday")) n = 0;
    else n = -1;
    return n;
}