// 3_33_ReversingLinkedList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//Given a constant K and a singly linked list L, you are supposed to reverse the links of every K elements on L. For example, given L being 1→2→3→4→5→6, if K=3, then you must output 3→2→1→6→5→4; if K=4, you must output 4→3→2→1→5→6.

//Input Specification :
//Each input file contains one test case.For each case, the first line contains the address of the first node, a positive N(≤10^5) which is the total number of nodes, and a positive K(≤N) which is the length of the sublist to be reversed.The address of a node is a 5 - digit nonnegative integer, and NULL is represented by - 1.
//Then N lines follow, each describes a node in the format :
//Address Data Next
//where Address is the position of the node, Data is an integer, and Next is the position of the next node.

//Output Specification :
//For each case, output the resulting ordered linked list.Each node occupies a line, and is printed in the same format as in the input.

//Sample Input :
//00100 6 4
//00000 4 99999
//00100 1 12309
//68237 6 - 1
//33218 3 00000
//99999 5 68237
//12309 2 33218

//Sample Output :
//00000 4 33218
//33218 3 12309
//2309 2 00100
//00100 1 99999
//99999 5 68237
//68237 6 - 1

#include <iostream>
#define MAXN 100010
using namespace std;

int main()
{
	int Data[MAXN];
	int Next[MAXN];
	int Node[MAXN];
	int startA, N, K;
	cin >> startA >> N >> K;
	for (int i = 0; i < N; i++)
	{
		int tA, tD, tN;
		cin >> tA >> tD >> tN;
		Data[tA] = tD;
		Next[tA] = tN;
	}
	int cnt = 0;
	//筛选节点
	while (startA != -1)
	{
		Node[cnt++] = startA;
		startA = Next[startA];
	}
	//逆转
	int sig = 0;
	for (int i = 0; i < cnt - cnt % K; i += K) {  // 每 K 个结点一个区间 
		for (int j = 0; j < K / 2; j++) {  // 反转链表
			int t = Node[i + j];
			Node[i + j] = Node[i + K - j - 1];
			Node[i + K - j - 1] = t;
		}
	}
	for (int i = 0; i < cnt - 1; i++)
		printf("%05d %d %05d\n", Node[i], Data[Node[i]], Node[i + 1]);
	printf("%05d %d -1\n", Node[cnt - 1], Data[Node[cnt - 1]]);
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
