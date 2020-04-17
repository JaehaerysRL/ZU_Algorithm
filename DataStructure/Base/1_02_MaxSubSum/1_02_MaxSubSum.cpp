// 1_02_MaxSubSum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//Maximum Subsequence Sum
//Given a sequence of K integers { N​1​, N2​, ..., N​K}.A continuous subsequence is defined to be{ N​i , N​i + 1​ , ..., Nj } where 1≤i≤j≤K.The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements.For example, given sequence{ -2, 11, -4, 13, -5, -2 }, its maximum subsequence is{ 11, -4, 13 } with the largest sum being 20.
//Now you are supposed to find the largest sum, together with the firstand the last numbers of the maximum subsequence.

//Input Specification :
//Each input file contains one test case.Each case occupies two lines.The first line contains a positive integer K(≤10000).The second line contains K numbers, separated by a space.
//Output Specification :
//For each test case, output in one line the largest sum, together with the firstand the last numbers of the maximum subsequence.The numbers must be separated by one space, but there must be no extra space at the end of a line.In case that the maximum subsequence is not unique, output the one with the smallest indices iand j(as shown by the sample case).If all the K numbers are negative, then its maximum sum is defined to be 0, and you are supposed to output the firstand the last numbers of the whole sequence.

//Sample Input :
//10
//- 10 1 2 3 4 - 5 - 23 3 7 - 21
//Sample Output :
//10 1 4



#include <iostream>

int main()
{
    int N;
    scanf("%d", &N);
    int num[N], thisSum, startIndex, tempIndex, endIndex, maxSum;
    thisSum = startIndex = tempIndex = 0;endIndex = N - 1;maxSum = -1;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &num[i]);
        thisSum += num[i];
        if (thisSum < 0) {
            thisSum = 0;
            tempIndex = i + 1;
        }
        else if (thisSum > maxSum) {
            maxSum = thisSum;
            startIndex = tempIndex;
            endIndex = i;
        }
    }
    if (maxSum < 0)maxSum = 0;
    printf("%d %d %d", maxSum, num[startIndex], num[endIndex]);
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
