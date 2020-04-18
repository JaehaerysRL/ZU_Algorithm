// 2_33_两个有序链表序列的交集.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//已知两个非降序链表序列S1与S2，设计函数构造出S1与S2的交集新链表S3。

//输入格式:
//输入分两行，分别在每行给出由若干个正整数构成的非降序序列，用−1表示序列的结尾（−1不属于这个序列）。数字用空格间隔。

//输出格式 :
//在一行中输出两个输入序列的交集序列，数字间用空格分开，结尾不能有多余空格；若新链表为空，输出NULL。

//输入样例 :
//1 2 5 - 1
//2 4 5 8 10 - 1

//输出样例:
//2 5

#include <iostream>

using namespace std;

typedef struct Node* PtrToNode;
struct Node
{
    int Data;
    PtrToNode Next;
};
typedef PtrToNode List;

int main()
{
    List l1, l2, p1, p2, q;
    l1 = (List)malloc(sizeof(struct Node));
    l2 = (List)malloc(sizeof(struct Node));
    l1->Next = NULL;l2->Next = NULL;
    p1 = l1;p2 = l2;
    int tmp, sig = 0;
    while (true)
    {
        cin >> tmp;
        if (tmp == -1) break;
        List t = (List)malloc(sizeof(struct Node));
        t->Data = tmp;
        t->Next = NULL;
        p1->Next = t;
        p1 = p1->Next;
    }
    p1 = l1->Next, q = p2;
    while (true)
    {
        cin >> tmp;
        if (tmp == -1) break;
        List t = (List)malloc(sizeof(struct Node));
        t->Data = tmp;
        t->Next = NULL;
        p2->Next = t;
        p2 = p2->Next;
        while (p1 && p1->Data < p2->Data) p1 = p1->Next;
        if (p1 && p1->Data == p2->Data) {
            if (sig == 0) cout << p1->Data;
            else cout << " " << p1->Data;
            p1 = p1->Next;
            sig++;
        }
    }
    if (sig == 0)cout << "NULL";
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
