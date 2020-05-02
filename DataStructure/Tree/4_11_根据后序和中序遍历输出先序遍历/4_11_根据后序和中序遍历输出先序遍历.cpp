// 4_11_根据后序和中序遍历输出先序遍历.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//本题要求根据给定的一棵二叉树的后序遍历和中序遍历结果，输出该树的先序遍历结果。

//输入格式:
//第一行给出正整数N(≤30)，是树中结点的个数。随后两行，每行给出N个整数，分别对应后序遍历和中序遍历结果，数字间以空格分隔。题目保证输入正确对应一棵二叉树。

//输出格式 :
//在一行中输出Preorder:以及该树的先序遍历结果。数字间有1个空格，行末不得有多余空格。

//输入样例 :
//7
//2 3 1 5 7 6 4
//1 2 3 4 5 6 7
//输出样例 :
//Preorder : 4 1 3 2 6 5 7

//本题不建树更好

#include <iostream>
#define MAXN 30
using namespace std;

void PreorderTraversal(int Inorder[], int Postorder[], int N) {
	if (N <= 0) return;
	cout << " " << Postorder[N - 1];
	int p;
	for (p = 0; p < N; p++)
	{
		if (Inorder[p] == Postorder[N - 1]) break;
	}
	PreorderTraversal(Inorder, Postorder, p);
	PreorderTraversal(Inorder + p + 1, Postorder + p, N - p - 1);
}

int main()
{
	int N, i, Inorder[MAXN], Postorder[MAXN];
	cin >> N;
	for (i = 0; i < N; i++)
		cin >> Postorder[i];
	for (i = 0; i < N; i++)
		cin >> Inorder[i];
	cout << "Preorder:";
	PreorderTraversal(Inorder, Postorder, N);
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
