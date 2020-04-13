// 6-5 求单链表结点的阶乘和 (15分)
//本题要求实现一个函数，求单链表L结点的阶乘和。这里默认所有结点的值非负，且题目保证结果在int范围内。

//输入样例：
//3
//5 3 6

//输出样例：
//846

#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrToNode;
struct Node {
    int Data; /* 存储结点数据 */
    PtrToNode Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

int FactorialSum( List L );

int main()
{
    int N, i;
    List L, p;

    scanf("%d", &N);
    L = NULL;
    for ( i=0; i<N; i++ ) {
        p = (List)malloc(sizeof(struct Node));
        scanf("%d", &p->Data);
        p->Next = L;  L = p;
    }
    printf("%d\n", FactorialSum(L));

    return 0;
}

/* 你的代码将被嵌在这里 */
int FactorialSum(List L) {
    List p = L;
    int sum = 0, temp;
    while (p) {
        temp = 1;
        for (int i = p->Data; i >= 2; i--)
        {
            temp *= i;
        }
        sum += temp;
        p = p->Next;
    }
    return sum;
}