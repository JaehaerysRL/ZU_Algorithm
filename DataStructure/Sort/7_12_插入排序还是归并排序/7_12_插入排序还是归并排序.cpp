// 7_12_插入排序还是归并排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

int IsInsert(int* A, int* B, int N);
int MergeLenth(int* A, int N);
void NextInsert(int* A, int N, int K);
void NextMerge(int* A, int N);
void PrintResult(int* A, int N);

int main()
{
	int N, K;
	cin >> N;
	int* A = (int*)malloc(sizeof(int) * N);
	int* B = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < N; i++)
		cin >> B[i];
	K = IsInsert(A, B, N);
	if (K)
		NextInsert(B, N, K);
	else
		NextMerge(B, N);
}

int IsInsert(int* A, int* B, int N) {
	int i, k;
	for (i = 1; i < N; i++)
		if (B[i] < B[i - 1]) break;
	k = i;
	for (; i < N; i++)
		if (B[i] != A[i]) break;
	if (i == N) return k;
	else return 0;
}
void PrintResult(int* A, int N) {
	cout << A[0];
	for (int i = 1; i < N; i++)
		cout << " " << A[i];
}
void NextInsert(int* A, int N, int K) {
	int i, tmp;
	cout << "Insertion Sort" << endl;
	tmp = A[K];
	for (i = K - 1; i >= 0; i--)
		if (tmp < A[i]) A[i + 1] = A[i];
		else break;
	A[i + 1] = tmp;
	PrintResult(A, N);
}
int MergeLenth(int* A, int N) {
	int i, j;
	for (j = 2; j <= N; j *= 2)
	{
		for (i = j; i < N; i += (j + j))
			if (A[i - 1] > A[i]) break;
		if (i < N) break;
	}
	return j;
}
void NextMerge(int* A, int N) {
	int L, p, i, p1, p2;
	int* T = (int*)malloc(sizeof(int) * N);
	cout << "Merge Sort" << endl;
	L = MergeLenth(A, N);
	p = 0;
	for (i = 0; i < (N-L-L); i+=(L+L))
	{
		p1 = i; p2 = i + L;
		while ((p1<(i+L))&&(p2<(i+L+L)))
		{
			if (A[p1] > A[p2]) T[p++] = A[p2++];
			else T[p++] = A[p1++];
		}
		while (p1 < (i + L)) T[p++] = A[p1++];
		while (p2 < (i + L + L)) T[p++] = A[p2++];
	}
	if ((N - i) > L) {
		p1 = i; p2 = i + L;
		while ((p1 < (i + L)) && (p2 < N))
		{
			if (A[p1] > A[p2]) T[p++] = A[p2++];
			else T[p++] = A[p1++];
		}
		while (p1 < (i + L)) T[p++] = A[p1++];
		while (p2 < N) T[p++] = A[p2++];
	}
	else
		while (i < N) {
			T[i] = A[i];
			i++;
		}
	PrintResult(T, N);
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
