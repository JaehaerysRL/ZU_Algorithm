﻿// 7-36 韩信点兵 (10分)
//在中国数学史上，广泛流传着一个“韩信点兵”的故事：韩信是汉高祖刘邦手下的大将，他英勇善战，智谋超群，为汉朝建立了卓越的功劳。据说韩信的数学水平也非常高超，他在点兵的时候，为了知道有多少兵，同时又能保住军事机密，便让士兵排队报数：

//按从1至5报数，记下最末一个士兵报的数为1；
//再按从1至6报数，记下最末一个士兵报的数为5；
//再按从1至7报数，记下最末一个士兵报的数为4；
//最后按从1至11报数，最末一个士兵报的数为10；
//请编写程序计算韩信至少有多少兵。

//输入格式：
//本题无输入

//输出格式：
//输出韩信至少拥有的士兵人数

#include <stdio.h>
#include <math.h>

int main()
{
    int sum = 0, judge = 0;
    while (judge == 0) {
        sum++;
        if (sum % 5 == 1 && sum % 6 == 5 && sum % 7 == 4 && sum % 11 == 10) judge = 1;
    }
    printf("%d", sum);
}