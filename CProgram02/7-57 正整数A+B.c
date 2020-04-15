// 7-57 正整数A+B (15分)
//题的目标很简单，就是求两个正整数A和B的和，其中A和B都在区间[1,1000]。稍微有点麻烦的是，输入并不保证是两个正整数。

//输入格式：
//输入在一行给出A和B，其间以空格分开。问题是A和B不一定是满足要求的正整数，有时候可能是超出范围的数字、负数、带小数点的实数、甚至是一堆乱码。
//注意：我们把输入中出现的第1个空格认为是A和B的分隔。题目保证至少存在一个空格，并且B不是一个空字符串。

//输出格式：
//如果输入的确是两个正整数，则按格式A + B = 和输出。如果某个输入不合要求，则在相应位置输出?，显然此时和也是?。

//输入样例1：
//123 456

//输出样例1：
//123 + 456 = 579

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int IsStanderd(char* A);
int main() {
    char A[20];
    char B[20];
    scanf("%s", A);
    getchar();    //这里必须加一个来读取空格，不然getchar读到缓冲区第一位就是空格
    gets(B);      //测试点3就是说第一个空格之后的是第二个B，所以B中也可能出现空格.要认真读题干，没有认真读题干在测试点3上卡了半天
    int a = atoi(A);
    int b = atoi(B);
    if (IsStanderd(A) == 0 || IsStanderd(B) == 0) { //不标准
        if (IsStanderd(A) == 0 && IsStanderd(B) == 0) {
            printf("? + ? = ?");
            return 0;
        }
        else if (IsStanderd(A) == 0) {
            printf("? + %d = ?", b);
            return 0;
        }
        else {
            printf("%d + ? = ?", a);
            return 0;
        }
    }
    else {//标准的
        int c = a + b;
        printf("%d + %d = %d", a, b, c);
    }
    return 0;
}

int IsStanderd(char* A) {
    int a = atoi(A);
    int i;
    for (i = 0;i < strlen(A);i++) {
        if (A[i] < '0' || A[i]>'9') {
            return 0;
        }
    }
    if (a < 1 || a>1000) {
        return 0;
    }
    return 1; //标准的
}