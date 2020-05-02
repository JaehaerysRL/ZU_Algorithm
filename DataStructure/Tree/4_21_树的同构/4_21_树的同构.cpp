// 4_21_树的同构.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//给定两棵树T1和T2。如果T1可以通过若干次左右孩子互换就变成T2，则我们称两棵树是“同构”的。例如图1给出的两棵树就是同构的，因为我们把其中一棵树的结点A、B、G的左右孩子互换后，就得到另外一棵树。而图2就不是同构的。
//现给定两棵树，请你判断它们是否是同构的。
//输入格式:
//输入给出2棵二叉树树的信息。对于每棵树，首先在一行中给出一个非负整数N(≤10)，即该树的结点数（此时假设结点从0到N−1编号）；随后N行，第i行对应编号第i个结点，给出该结点中存储的1个英文大写字母、其左孩子结点的编号、右孩子结点的编号。如果孩子结点为空，则在相应位置上给出“ - ”。给出的数据间用一个空格分隔。注意：题目保证每个结点中存储的字母是不同的。
//输出格式 :
//如果两棵树是同构的，输出“Yes”，否则输出“No”

#include <iostream>
#define MAXN 10
using namespace std;

typedef struct TNode
{
	char Data;
	int Left;
	int Right;
}BinTree;

bool CMP(BinTree BT1[], BinTree BT2[], int root1, int root2);

int main()
{
	BinTree BT1[MAXN], BT2[MAXN];
	int N1, N2, r1 = -1, r2 = -1, rSig1[MAXN] = { 0 }, rSig2[MAXN] = { 0 }, tmp;
	char tl, tr, td;
	scanf_s("%d", &N1);
	getchar();
	for (int i = 0; i < N1; i++)
	{
		scanf_s("%c %c %c", &td, 1, &tl, 1, &tr, 1);
		getchar();
		BT1[i].Data = td;
		if (tl != 45) {
			tmp = tl - 48;
			BT1[i].Left = tmp;
			rSig1[tmp] = 1;
		}
		else BT1[i].Left = -1;
		if (tr != 45) {
			tmp = tr - 48;
			BT1[i].Right = tmp;
			rSig1[tmp] = 1;
		}
		else BT1[i].Right = -1;
	}
	scanf_s("%d", &N2);
	getchar();
	for (int i = 0; i < N2; i++)
	{
		scanf_s("%c %c %c", &td, 1, &tl, 1, &tr, 1);
		getchar();
		BT2[i].Data = td;
		if (tl != 45) {
			tmp = tl - 48;
			BT2[i].Left = tmp;
			rSig2[tmp] = 1;
		}
		else BT2[i].Left = -1;
		if (tr != 45) {
			tmp = tr - 48;
			BT2[i].Right = tmp;
			rSig2[tmp] = 1;
		}
		else BT2[i].Right = -1;
	}
	if (N1 != N2) {//节点数不同直接否定
		cout << "No" << endl;
	}
	else {
		for (int i = 0; i < N1; i++)
		{
			if (rSig1[i] == 0) r1 = i;
			if (rSig2[i] == 0) r2 = i;
		}
		if (CMP(BT1, BT2, r1, r2)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}

bool CMP(BinTree BT1[], BinTree BT2[], int root1, int root2) {
	if (root1 < 0 && root2 < 0) return true;
	if (root1 < 0 || root2 < 0) return false;
	if (BT1[root1].Data != BT2[root2].Data) return false;
	if (CMP(BT1, BT2, BT1[root1].Left, BT2[root2].Left) && CMP(BT1, BT2, BT1[root1].Right, BT2[root2].Right))
		return true;
	else if (CMP(BT1, BT2, BT1[root1].Left, BT2[root2].Right) && CMP(BT1, BT2, BT1[root1].Right, BT2[root2].Left))
		return true;
	else return false;
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
