// 进阶实验1-3.1 两个有序序列的中位数 (25分)
//已知有两个等长的非降序序列S1, S2, 设计函数求S1与S2并集的中位数。有序序列A​0,A1​, ⋯, AN−1​​的中位数指A​(N−1)/2的值, 即第⌊(N + 1) / 2⌋个数（A0为第1个数）。

//输入格式 :
//输入分三行。第一行给出序列的公共长度N（0 < N≤100000），随后每行输入一个序列的信息，即N个非降序排列的整数。数字用空格间隔。
//输出格式 :
//在一行中输出两个输入序列的并集序列的中位数。

//本题奇数各剩1个取小者，偶数各剩2个取次小者


#include <iostream>

int main()
{
    int N, mid;
    scanf_s("%d", &N);
    int* numA = (int*)malloc(sizeof(int) * N), * numB = (int*)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
    {
        scanf_s("%d", &numA[i]);
    }
    for (int i = 0; i < N; i++)
    {
        scanf_s("%d", &numB[i]);
    }
    int LA, LB, RA, RB, midA, midB, count, maxCount;
    LA = LB = 0; RA = RB = N - 1; count = 0; maxCount = (N - 1) / 2 * 2;
    midA = numA[(LA + RA) / 2]; midB = numB[(LB + RB) / 2];
    while (midA != midB && count<maxCount)
    {
        if (midA < midB) {
            LA++; RB--;
        }
        else
        {
            LB++; RA--;
        }
        midA = numA[(LA + RA) / 2]; midB = numB[(LB + RB) / 2];
        count++;
        if (count >= maxCount)break;
    }
    if (N % 2 == 1) mid = midA < midB ? midA : midB;
    else {
        if (numA[RA] < numB[LB])mid = numA[RA];
        else if (numB[RB] < numA[LA])mid = numB[RB];
        else if (numA[LA] > numB[LB])mid = numA[LA];
        else mid = numB[LB];
    }
    printf("%d",mid);
    return 0;
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
