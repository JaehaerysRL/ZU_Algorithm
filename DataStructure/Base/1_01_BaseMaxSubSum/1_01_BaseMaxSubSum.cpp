// 实例1.1 最大子列和问题 (20分)
// 在一行中输出最大子列和。如果序列中所有整数皆为负数，则输出0。

#include <iostream>

int main()
{
    int N;
    scanf("%d", &N);
    int num;
    int maxSum = 0, thisSum = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &num);
        thisSum += num;
        if (thisSum > maxSum) maxSum = thisSum;
        else if (thisSum < 0) thisSum = 0;
    }
    printf("%d", maxSum);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
