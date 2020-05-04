// 4_28_部落.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#define MAXN 10000
using namespace std;

typedef int ElementType;
typedef int SetName;
typedef ElementType SetType[MAXN];
void Initialization(SetType S, int n) {
	for (int i = 0; i < n; i++)
	{
		S[i] = -1;
	}
}
//路径压缩
SetName Find(SetType S, ElementType X) {
	if (S[X] < 0)
		return X;
	else
		return S[X] = Find(S, S[X]);
}
//按秩合并
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
void InputLink(SetType S, ElementType u, ElementType v) {
	SetName Root1, Root2;
	Root1 = Find(S, u - 1);
	Root2 = Find(S, v - 1);
	if (Root1 != Root2) Union(S, Root1, Root2);
}
void CheckLink(SetType S) {
	ElementType u, v;
	SetName Root1, Root2;
	cin >> u >> v;
	Root1 = Find(S, u - 1);
	Root2 = Find(S, v - 1);
	if (Root1 == Root2) cout << "Y" << endl;
	else cout << "N" << endl;
}
int CheckNet(SetType S, int n) {
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (S[i] < 0)cnt++;
	}
	return cnt;
}

int main()
{
	SetType S;
	Initialization(S, MAXN);
	int N, K, U, V, Q, pNum = 0, sNum = 0;
	cin >> N;
	for (int k = 0; k < N; k++)
	{
		cin >> K >> U;
		if (U > pNum) pNum = U;
		for (int j = 1; j < K; j++)
		{
			cin >> V;
			if (V > pNum) pNum = V;
			InputLink(S, U, V);
		}
	}
	sNum = CheckNet(S, pNum);
	cout << pNum << " " << sNum << endl;
	cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		CheckLink(S);
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
