// 4_16_树种统计.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//随着卫星成像技术的应用，自然资源研究机构可以识别每一棵树的种类。请编写程序帮助研究人员统计每种树的数量，计算每种树占总数的百分比。

//输入格式:
//输入首先给出正整数N（≤10^5），随后N行，每行给出卫星观测到的一棵树的种类名称。种类名称由不超过30个英文字母和空格组成（大小写不区分）。
//输出格式 :
//按字典序递增输出各种树的种类名称及其所占总数的百分比，其间以空格分隔，保留小数点后4位。
//用cin.getline读取

#include <iostream>
#include <string.h>
#define MAXN 100001
#define MAXS 31
using namespace std;

typedef struct TNode* BinTree;
struct TNode
{
	char Data[MAXS];
	int Cnt;
	BinTree Left;
	BinTree Right;
};

BinTree Insert(BinTree BST, char* X);
void Output(BinTree BST, int N);

int main()
{
	int N;
	char X[MAXS];
	BinTree T = NULL;
	cin >> N;
	getchar();
	for (int i = 0; i < N; i++)
	{
		cin.getline(X, MAXS);
		T = Insert(T, X);
	}
	Output(T, N);
}

BinTree Insert(BinTree BST, char* X) {
	if (!BST) {
		BST = (BinTree)malloc(sizeof(struct TNode));
		strcpy_s(BST->Data, X);
		BST->Cnt = 1;
		BST->Left = BST->Right = NULL;
	}
	else {
		int cmp = strcmp(X, BST->Data);
		if (cmp < 0)
			BST->Left = Insert(BST->Left, X);
		else if (cmp > 0)
			BST->Right = Insert(BST->Right, X);
		else BST->Cnt++;
	}
	return BST;
}
void Output(BinTree BST, int N) {
	if (!BST)return;
	Output(BST->Left, N);
	printf("%s %.4lf%%\n", BST->Data, (double)BST->Cnt / (double)N * 100);
	Output(BST->Right, N);
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
