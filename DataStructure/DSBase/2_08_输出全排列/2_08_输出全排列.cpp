// 2_08_输出全排列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#define MAXN 9

void RightShift(int L[], int Left, int i) {
    int tmp = L[i];
    for (int j = i; j > Left; j--) L[j] = L[j - 1];
    L[Left] = tmp;
}

void LeftShift(int L[], int Left, int i) {
    int tmp = L[Left];
    for (int j = Left; j < i; j++) L[j] = L[j + 1];
    L[i] = tmp;
}


void Permutation(int L[], int Left, int Right) {
    if (Left == Right) {
        for (int i = 0; i <= Right; i++) printf("%d", L[i]);
        printf("\n");
    }
    else {
        for (int i = Left; i <= Right; i++)
        {
            RightShift(L, Left, i);
            Permutation(L, Left + 1, Right);
            LeftShift(L, Left, i);
        }
    }
}

int main()
{
    int n, L[MAXN];

    scanf("%d", &n);
	for (int i = 0; i < n; i++) L[i] = i + 1;
    Permutation(L, 0, n - 1);
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
