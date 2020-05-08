// 5_22_电话聊天狂人.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <string.h>
#define MAXN 20000
using namespace std;

#define KEYLENGTH 11                   /* 关键词字符串的最大长度 */
typedef char LElementType[KEYLENGTH + 1]; /* 关键词类型用字符串 */
typedef int Index;                     /* 散列地址类型 */
/******** 以下是单链表的定义 ********/
typedef struct LNode* PtrToLNode;
struct LNode {
	LElementType Data;
	int Freq;
	PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;
/******** 以上是单链表的定义 ********/
typedef struct LTblNode* LHashTable; /* 散列表类型 */
struct LTblNode {   /* 散列表结点定义 */
	int TableSize; /* 表的最大长度 */
	List Heads;    /* 指向链表头结点的数组 */
};

int NextPrime(int N)
{ /* 返回大于N且不超过MAXTABLESIZE的最小素数 */
	int i, p = (N % 2) ? N + 2 : N + 1; /*从大于N的下一个奇数开始 */

	while (p <= MAXN) {
		for (i = (int)sqrt(p); i > 2; i--)
			if (!(p % i)) break; /* p不是素数 */
		if (i == 2) break; /* for正常结束，说明p是素数 */
		else  p += 2; /* 否则试探下一个奇数 */
	}
	return p;
}

LHashTable CreateTable(int TableSize)
{
	LHashTable H;
	int i;
	H = (LHashTable)malloc(sizeof(struct LTblNode));
	H->TableSize = NextPrime(TableSize);
	H->Heads = (List)malloc(H->TableSize * sizeof(struct LNode));
	/* 初始化表头结点 */
	for (i = 0; i < H->TableSize; i++) {
		H->Heads[i].Data[0] = '\0';
		H->Heads[i].Next = NULL;
		H->Heads[i].Freq = 0;
	}
	return H;
}

int Hash(char* Key, int TableSize) {
	int H;
	H = 1000 * (Key[7] - '0') + 100 * (Key[8] - '0') + 10 * (Key[9] - '0') + 1 * (Key[10] - '0');
	return H % TableSize;
}

Position Find(LHashTable H, LElementType Key)
{
	Position P;
	Index Pos;

	Pos = Hash(Key, H->TableSize); /* 初始散列位置 */
	P = H->Heads[Pos].Next; /* 从该链表的第1个结点开始 */
	/* 当未到表尾，并且Key未找到时 */
	while (P && strcmp(P->Data, Key))
		P = P->Next;

	return P; /* 此时P或者指向找到的结点，或者为NULL */
}

void Insert(LHashTable H, LElementType Key)
{
	Position P, NewCell;
	Index Pos;

	P = Find(H, Key);
	if (!P) { /* 关键词未找到，可以插入 */
		NewCell = (Position)malloc(sizeof(struct LNode));
		strcpy(NewCell->Data, Key);
		NewCell->Freq = 1;
		Pos = Hash(Key, H->TableSize); /* 初始散列位置 */
		/* 将NewCell插入为H->Heads[Pos]链表的第1个结点 */
		NewCell->Next = H->Heads[Pos].Next;
		H->Heads[Pos].Next = NewCell;
	}
	else { /* 关键词已存在 */
		P->Freq++;
	}
}

int main()
{
	int N;
	cin >> N;
	LElementType Key;
	LHashTable H = CreateTable(MAXN / 2);
	for (int i = 0; i < 2*N; i++)
	{
		cin >> Key;
		Insert(H, Key);
	}
	int cnt = 0, maxFreq = 0;
	for (int i = 0; i < H->TableSize; i++)
	{
		Position P = H->Heads[i].Next;
		while (P)
		{
			if (P->Freq > maxFreq) {
				maxFreq = P->Freq;
				cnt = 1;
				strcpy(Key, P->Data);
			}
			else if (P->Freq == maxFreq) {
				cnt++;
				if (strcmp(P->Data, Key) < 0) strcpy(Key, P->Data);
			}
			P = P->Next;
		}
	}
	cout << Key << " " << maxFreq;
	if (cnt > 1)cout << " " << cnt << endl;
	else cout << endl;
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
