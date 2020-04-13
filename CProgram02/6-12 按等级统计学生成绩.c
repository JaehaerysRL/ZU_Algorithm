// 6-12 按等级统计学生成绩 (20分)
//本题要求实现一个根据学生成绩设置其等级，并统计不及格人数的简单函数。

//输入样例：
//4
//31001 annie 85
//31002 bonny 75
//31003 carol 70
//31007 pam 50
  
//输出样例：
//The count for failed (<60): 1
//The grades:
//31001 annie A
//31002 bonny B
//31003 carol B
//31007 pam C

#include <stdio.h>
#define MAXN 10

struct student{
    int num;
    char name[20];
    int score;
    char grade;
};

int set_grade( struct student *p, int n );

int main()
{   struct student stu[MAXN], *ptr;
    int n, i, count;

    ptr = stu;
    scanf("%d\n", &n);
    for(i = 0; i < n; i++){
       scanf("%d%s%d", &stu[i].num, stu[i].name, &stu[i].score);
    } 
   count = set_grade(ptr, n);
   printf("The count for failed (<60): %d\n", count);
   printf("The grades:\n"); 
   for(i = 0; i < n; i++)
       printf("%d %s %c\n", stu[i].num, stu[i].name, stu[i].grade);
    return 0;
}

/* 你的代码将被嵌在这里 */
int set_grade(struct student* p, int n) {
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (p[i].score >= 85) p[i].grade = 'A';
        else if (p[i].score >= 70) p[i].grade = 'B';
        else if (p[i].score >= 60) p[i].grade = 'C';
        else {
            p[i].grade = 'D';
            c++;
        }
    }
    return c;
}