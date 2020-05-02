// 4_17_文件传输.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//当两台计算机双向连通的时候，文件是可以在两台机器间传输的。给定一套计算机网络，请你判断任意两台指定的计算机之间能否传输文件？

//输入格式：
//首先在第一行给出网络中计算机的总数 N(2≤N≤10^4)，于是我们假设这些计算机从 1 到 N 编号。随后每行输入按以下格式给出：
//I c1 c2
//其中I表示在计算机c1和c2之间加入连线，使它们连通；或者是
//C c1 c2
//其中C表示查询计算机c1和c2之间能否传输文件；又或者是
//S
//这里S表示输入终止。

//输出格式：
//对每个C开头的查询，如果c1和c2之间可以传输文件，就在一行中输出"yes"，否则输出"no"。当读到终止符时，在一行中输出"The network is connected."如果网络中所有计算机之间都能传输文件；或者输出"There are k components."，其中k是网络中连通集的个数。

#include <iostream>
using namespace std;

#define MAXSIZE 10001
typedef int ElementType;
typedef int SetName;
typedef ElementType SetType[MAXSIZE];
SetName Find(SetType S, ElementType X);
void Union(SetType S, SetName Root1, SetName Root2);
void Initialization(SetType S, int n);
void InputLink(SetType S);
void CheckLink(SetType S);
void CheckNet(SetType S, int n);

int main()
{
	SetType S;
	int n;
	char opt;
	cin >> n;
	getchar();
	Initialization(S, n);
	do {
		scanf_s("%c", &opt);
		switch (opt)
		{
		case 'I':InputLink(S); break;
		case 'C':CheckLink(S); break;
		case 'S':CheckNet(S, n); break;
		default:break;
		}
	} while (opt != 'S');
}

void Initialization(SetType S, int n) {
	for (int i = 0; i < n; i++)
	{
		S[i] = -1;
	}
}
void Union(SetType S, SetName Root1, SetName Root2) {
	if (S[Root2] < S[Root1]) {
		S[Root2] += S[Root1];
		S[Root1] = Root2;
	}
	else {
		S[Root1] += S[Root2];
		S[Root2] = Root1;
	}
}
SetName Find(SetType S, ElementType X) {
	if (S[X] < 0)
		return X;
	else
		return S[X] = Find(S, S[X]);
}
void InputLink(SetType S) {
	ElementType u, v;
	SetName Root1, Root2;
	cin >> u >> v;
	getchar();
	Root1 = Find(S, u - 1);
	Root2 = Find(S, v - 1);
	if (Root1 != Root2) Union(S, Root1, Root2);
}
void CheckLink(SetType S) {
	ElementType u, v;
	SetName Root1, Root2;
	cin >> u >> v;
	getchar();
	Root1 = Find(S, u - 1);
	Root2 = Find(S, v - 1);
	if (Root1 == Root2) cout << "yes" << endl;
	else cout << "no" << endl;
}
void CheckNet(SetType S, int n) {
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (S[i] < 0)cnt++;
	}
	if (cnt == 1) cout << "The network is connected." << endl;
	else cout << "There are " << cnt << " components." << endl;
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
