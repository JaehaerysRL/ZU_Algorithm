// 4_34_笛卡尔树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//笛卡尔树是一种特殊的二叉树，其结点包含两个关键字K1和K2。首先笛卡尔树是关于K1的二叉搜索树，即结点左子树的所有K1值都比该结点的K1值小，右子树则大。其次所有结点的K2关键字满足优先队列（不妨设为最小堆）的顺序要求，即该结点的K2值比其子树中所有结点的K2值小。给定一棵二叉树，请判断该树是否笛卡尔树。

//输入格式:
//输入首先给出正整数N（≤1000），为树中结点的个数。随后N行，每行给出一个结点的信息，包括：结点的K1值、K2值、左孩子结点编号、右孩子结点编号。设结点从0~(N - 1)顺序编号。若某结点不存在孩子结点，则该位置给出−1。
//输出格式 :
//输出YES如果该树是一棵笛卡尔树；否则输出NO。

#include <iostream>
#define MAXN 1000
using namespace std;

typedef struct TNode* BinTree;
struct TNode
{
	int K1;
	int K2;
	int Left;
	int Right;
};

bool IsDCT(BinTree T, int* min, int* max, int root) {
	if (root == -1) return true;
	if (T[root].Left == -1 && T[root].Right == -1) {
		*min = *max = T[root].K1;
		return true;
	}
	bool LeftFlag, RightFlag;
	LeftFlag = RightFlag = false;
	int lmin, lmax, rmin, rmax;
	if (T[root].Left == -1 || (IsDCT(T, &lmin, &lmax, T[root].Left) && T[root].K1 > lmax && T[root].K2 < T[T[root].Left].K2))
		LeftFlag = true;
	if (T[root].Right == -1 || (IsDCT(T, &rmin, &rmax, T[root].Right) && T[root].K1 < rmin && T[root].K2 < T[T[root].Right].K2))
		RightFlag = true;
	if (LeftFlag && RightFlag) {
		if (T[root].Left != -1)* min = lmin;
		else *min = T[root].K1;
		if (T[root].Right != -1)* max = rmax;
		else *max = T[root].K1;
		return true;
	}
	else return false;
}
bool IsDCT(BinTree T, int root) {
	int minT, maxT;
	minT = maxT = -1;
	return IsDCT(T, &minT, &maxT, root);
}

int main()
{
	int N, rSig[MAXN] = { 0 }, root = 0;
	cin >> N;
	BinTree T = (BinTree)malloc(sizeof(struct TNode) * N);
	for (int i = 0; i < N; i++) {
		cin >> T[i].K1 >> T[i].K2 >> T[i].Left >> T[i].Right;
		if(T[i].Left>=0) rSig[T[i].Left] = 1;
		if(T[i].Right >= 0) rSig[T[i].Right] = 1;
	}
	for (int i = 0; i < N; i++)
		if (rSig[i] == 0) root = i;
	if (IsDCT(T, root)) cout << "YES" << endl;
	else cout << "NO" << endl;
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
