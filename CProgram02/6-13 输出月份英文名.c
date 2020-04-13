// 6-13 输出月份英文名 (15分)
//本题要求实现函数，可以返回一个给定月份的英文名称。
//函数getmonth应返回存储了n对应的月份英文名称的字符串头指针。如果传入的参数n不是一个代表月份的数字，则返回空指针NULL。

//输入样例1：
//5

//输出样例1：
//May

#include <stdio.h>

char *getmonth( int n );

int main()
{
    int n;
    char *s;

    scanf("%d", &n);
    s = getmonth(n);
    if ( s==NULL ) printf("wrong input!\n");
    else printf("%s\n", s);

    return 0;
}

/* 你的代码将被嵌在这里 */
char *getmonth( int n )
{
    switch(n)
    {
    case 1:return "January";
    case 2:return "February";
    case 3:return "March";
    case 4:return "April";
    case 5:return "May";
    case 6:return "June";
    case 7:return "July";
    case 8:return "August";
    case 9:return "September";
    case 10:return "October";
    case 11:return "November";
    case 12:return "December";
    default:return NULL;
    }
}
