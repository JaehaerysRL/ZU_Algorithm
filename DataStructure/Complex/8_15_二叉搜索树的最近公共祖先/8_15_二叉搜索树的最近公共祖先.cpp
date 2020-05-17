// 8_15_二叉搜索树的最近公共祖先.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#define MAXN 10001
using namespace std;

struct tree
{
	int Data, Height;
	tree* Last, * Left, * Right;
}*head;
int q[MAXN], z[MAXN], m, n;
map<int, tree*> mp;
tree* createNode(int d, int h)
{
	tree* p = new tree();
	p->Data = d;
	mp[d] = p;
	p->Height = h;
	p->Last = p->Left = p->Right = NULL;
	return p;
}
tree* createTree(int ql, int qr, int zl, int zr, int h)
{
	tree* p = createNode(q[ql], h);
	for (int i = zl; i <= zr; i++)
	{
		if (z[i] == q[ql])
		{
			if (i > zl)p->Left = createTree(ql + 1, ql + i - zl, zl, i - 1, h + 1), p->Left->Last = p;
			if (i < zr)p->Right = createTree(ql + i - zl + 1, qr, i + 1, zr, h + 1), p->Right->Last = p;
			break;
		}
	}
	return p;
}
tree* createTre(int l, int r, int h)
{
	tree* p = createNode(q[l], h);
	for (int i = l + 1; i <= r + 1; i++)
	{
		if (i == r + 1 || q[i] >= q[l])
		{
			if (i > l + 1)p->Left = createTre(l + 1, i - 1, h + 1), p->Left->Last = p;
			if (r >= i)p->Right = createTre(i, r, h + 1), p->Right->Last = p;
			return p;
		}
	}
}
void check(int a, int b)
{
	if (mp[a] == NULL && mp[b] == NULL)printf("ERROR: %d and %d are not found.\n", a, b);
	else if (mp[a] == NULL)printf("ERROR: %d is not found.\n", a);
	else if (mp[b] == NULL)printf("ERROR: %d is not found.\n", b);
	else
	{
		tree* t1 = mp[a], * t2 = mp[b];
		while (t1->Height != t2->Height)
		{
			if (t1->Height > t2->Height)t1 = t1->Last;
			else t2 = t2->Last;
		}
		if (t1 == t2)
		{
			printf("%d is an ancestor of %d.\n", t1->Data, a == t1->Data ? b : a);
			return;
		}
		t1 = t1->Last;
		t2 = t2->Last;
		while (t1 != t2)
		{
			t1 = t1->Last;
			t2 = t2->Last;
		}
		printf("LCA of %d and %d is %d.\n", a, b, t1->Data);
	}
}
int main()
{
	int a, b;
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &q[i]);
	}
	head = createTre(0, n - 1, 0);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &a, &b);
		check(a, b);
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
