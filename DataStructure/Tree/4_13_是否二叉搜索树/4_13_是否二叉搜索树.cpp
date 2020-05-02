// 4_13_是否二叉搜索树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//本题要求实现函数，判断给定二叉树是否二叉搜索树。
//C语言本身没有重载，C++才行

#include <iostream>

typedef int ElementType;
typedef struct TNode* Position;
typedef Position BinTree;
struct TNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

BinTree BuildTree(); /* 由裁判实现，细节不表 */
bool IsBST(BinTree T);

int main()
{
	BinTree T;

	T = BuildTree();
	if (IsBST(T)) printf("Yes\n");
	else printf("No\n");

	return 0;
}
/* 你的代码将被嵌在这里 */
bool IsBST(BinTree T) {
	int minT, maxT;
	minT = maxT = -1;
	return IsBST(T, &minT, &maxT);
}
bool IsBST(BinTree T, int* min, int* max) {
	if (!T) return true;
	if (!T->Left && !T->Right) {
		*min = *max = T->Data;
		return true;
	}
	bool LeftFlag, RightFlag;
	LeftFlag = RightFlag = false;
	int lmin, lmax, rmin, rmax;
	if (!T->Left || (IsBST(T->Left, &lmin, &lmax) && T->Data > lmax)) LeftFlag = true;
	if (!T->Right || (IsBST(T->Right, &rmin, &rmax) && T->Data < rmin)) RightFlag = true;
	if (LeftFlag && RightFlag) {
		if (T->Left)* min = lmin;
		else *min = T->Data;
		if (T->Right)* max = rmax;
		else *max = T->Data;
		return true;
	}
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
