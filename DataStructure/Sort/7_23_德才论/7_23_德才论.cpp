// 7_23_德才论.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#define MAXN 9
using namespace std;

typedef struct _Node {
	char ID[MAXN];
	int de;
	int cai;
	int total;
	int rank;
}Node;
int H, L;

bool cmp(Node a, Node b) {
	if (a.rank == b.rank) {
		if (a.total == b.total)
			if (a.de == b.de)
				return (strcmp(a.ID, b.ID) < 0);
			else 
				return a.de > b.de;
		else
			return a.total > b.total;
	}
	else
		return a.rank < b.rank;
}

int main()
{
	int N, cnt = 0, tde, tcai;
	scanf_s("%d %d %d", &N, &L, &H);
	Node* P = (Node*)malloc(sizeof(Node) * N);
	for (int i = 0; i < N; i++)
	{
		char tid[MAXN];
		scanf_s("%s %d %d", tid, MAXN, &tde, &tcai);
		if (tde >= L && tcai >= L) {
			strcpy(P[cnt].ID, tid);
			P[cnt].de = tde; P[cnt].cai = tcai; P[cnt].total = tde + tcai;
			if (tde >= H) {
				if (tcai >= H) P[cnt].rank = 1;
				else P[cnt].rank = 2;
			}
			else if (tde >= tcai)
				P[cnt].rank = 3;
			else
				P[cnt].rank = 4;
			cnt++;
		}
	}
	sort(P, P + cnt, cmp);
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++) {
		printf("%s %d %d\n", P[i].ID, P[i].de, P[i].cai);
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
