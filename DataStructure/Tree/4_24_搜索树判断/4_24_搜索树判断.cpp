// 4_24_搜索树判断.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//对于二叉搜索树，我们规定任一结点的左子树仅包含严格小于该结点的键值，而其右子树包含大于或等于该结点的键值。如果我们交换每个节点的左子树和右子树，得到的树叫做镜像二叉搜索树。
//现在我们给出一个整数键值序列，请编写程序判断该序列是否为某棵二叉搜索树或某镜像二叉搜索树的前序遍历序列，如果是，则输出对应二叉树的后序遍历序列。
//输入格式:
//输入的第一行包含一个正整数N（≤1000），第二行包含N个整数，为给出的整数键值序列，数字间以空格分隔。
//输出格式 :
//输出的第一行首先给出判断结果，如果输入的序列是某棵二叉搜索树或某镜像二叉搜索树的前序遍历序列，则输出YES，否侧输出NO。如果判断结果是YES，下一行输出对应二叉树的后序遍历序列。数字间以空格分隔，但行尾不能有多余的空格。

#include <iostream>
#define MAXN 1001

using namespace std;

bool judgeBT(int num[], int left, int right, int* sig);
void preToPost(int pre[], int post[], int l1, int r1, int l2, int r2, int* sig);

int main()
{
	int N, pre[MAXN];
	int* sig = (int*)malloc(sizeof(int));
	*sig = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> pre[i];
	if (!judgeBT(pre, 0, N - 1, sig))
		cout << "NO" << endl;
	else {
		int post[MAXN];
		preToPost(pre, post, 0, N - 1, 0, N - 1, sig);
		cout << "YES" << endl;
		cout << post[0];
		for (int i = 1; i < N; i++)
			cout << " " << post[i];
	}
}

bool judgeBT(int num[], int left, int right, int* sig) {
	int root = num[left];
	if (right == left) return true;
	int p, flag = 0, tsig = 0;
	if (num[left + 1] < num[left]) {
		for (int i = left + 2; i <= right; i++)
		{
			if (num[i] >= root) {
				p = i - 1;
				flag = 1;//若为正树，左右子树皆存在
				break;
			}
		}
		if (flag == 0) return judgeBT(num, left + 1, right, sig);//递归验证单子树
		for (int i = p + 2; i <= right; i++) {//验证右子树
			if (num[i] < root) return false;
		}
		tsig = 1;//所验证是二叉搜索树
		if (*sig == 0)* sig = tsig;
		if (*sig != tsig) return false;
		return (judgeBT(num, left + 1, p, sig) && judgeBT(num, p + 1, right, sig));
	}
	else {
		for (int i = left + 2; i <= right; i++)
		{
			if (num[i] < root) {
				p = i - 1;
				flag = -1;//若为负树，左右子树皆存在
				break;
			}
		}
		if (flag == 0) return judgeBT(num, left + 1, right, sig);//递归验证子树
		for (int i = p + 2; i <= right; i++) {//验证右子树
			if (num[i] >= root) return false;
		}
		tsig = -1;//所验证是镜像二叉搜索树
		if (*sig == 0)* sig = tsig;
		if (*sig != tsig) return false;
		return (judgeBT(num, left + 1, p, sig) && judgeBT(num, p + 1, right, sig));
	}
}
void preToPost(int pre[], int post[], int l1, int r1, int l2, int r2, int* sig) {
	if (l1 > r1) return;
	int p = r1;
	post[r2] = pre[l1];//根节点
	if (l1 == r1) return;
	if (*sig == 1) {
		for (int i = l1 + 1; i <= r1; i++)
		{
			if (pre[i] >= pre[l1]) {
				p = i - 1;
				break;
			}
		}
		preToPost(pre, post, l1 + 1, p, l2, l2 + p - 1 - l1, sig);
		preToPost(pre, post, p + 1, r1, l2 + p - l1, r2 - 1, sig);
	}
	else {
		for (int i = l1 + 1; i <= r1; i++)
		{
			if (pre[i] < pre[l1]) {
				p = i - 1;
				break;
			}
		}
		preToPost(pre, post, l1 + 1, p, l2, l2 + p - 1 - l1, sig);
		preToPost(pre, post, p + 1, r1, l2 + p - l1, r2 - 1, sig);
	}
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
