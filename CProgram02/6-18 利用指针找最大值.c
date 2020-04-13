// 6-18 利用指针找最大值 (10分)
//本题要求实现一个简单函数，找出两个数中的最大值。

//输入样例：
//3 5

//输出样例：
//5

#include <stdio.h>

void findmax( int *px, int *py, int *pmax );

int main()
{	
    int max, x, y; 

    scanf("%d %d", &x, &y);
    findmax( &x, &y, &max );
    printf("%d\n", max);

    return 0;
} 

/* 你的代码将被嵌在这里 */
void findmax(int* px, int* py, int* pmax) {
    *pmax = *px > * py ? *px : *py;
}