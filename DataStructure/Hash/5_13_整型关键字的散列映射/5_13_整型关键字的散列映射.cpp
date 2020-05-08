// 5_13_整型关键字的散列映射.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <math.h>
#define MAXN 1000
using namespace std;

typedef int OElementType;    /* 关键词类型用整型 */
/* 散列单元状态类型，分别对应：有合法元素、空单元、有已删除元素 */
typedef enum { Legitimate, Empty } EntryType;

typedef struct HashEntry Cell; /* 散列表单元类型 */
struct HashEntry {
	OElementType Data; /* 存放元素 */
	EntryType Info;   /* 单元状态 */
};

typedef struct OTblNode* OHashTable; /* 散列表类型 */
struct OTblNode {   /* 散列表结点定义 */
	int TableSize; /* 表的最大长度 */
	Cell* Cells;   /* 存放散列单元数据的数组 */
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

int Hash(OElementType Key, int P) {

	return Key % P;
}

OHashTable CreateOTable(int TableSize)
{
	OHashTable H;
	int i;

	H = (OHashTable)malloc(sizeof(struct OTblNode));
	/* 保证散列表最大长度是素数 */
	H->TableSize = TableSize;
	/* 声明单元数组 */
	H->Cells = (Cell*)malloc(H->TableSize * sizeof(Cell));
	/* 初始化单元状态为“空单元” */
	for (i = 0; i < H->TableSize; i++)
		H->Cells[i].Info = Empty;

	return H;
}

int Find(OHashTable H, OElementType Key)
{
	int CurrentPos, NewPos;
	int CNum = 0; /* 记录冲突次数 */

	NewPos = CurrentPos = Hash(Key, H->TableSize); /* 初始散列位置 */
	/* 当该位置的单元非空，并且不是要找的元素时，发生冲突 */
	while (H->Cells[NewPos].Info != Empty && H->Cells[NewPos].Data != Key) {
		NewPos = (NewPos + 1) % H->TableSize;
		if (NewPos == CurrentPos) return -1;
	}
	return NewPos; /* 此时NewPos或者是Key的位置，或者是一个空单元的位置（表示找不到）*/
}

void InsertAndOutput(OHashTable H, OElementType Key)
{
	int Pos = Find(H, Key); /* 先检查Key是否已经存在 */

	if (H->Cells[Pos].Info != Legitimate) { /* 如果这个单元没有被占，说明Key可以插入在此 */
		H->Cells[Pos].Info = Legitimate;
		H->Cells[Pos].Data = Key;
	}
	cout << Pos;
}


int main()
{
	int N, P, K;
	cin >> N >> P;
	OHashTable H = CreateOTable(P);
	cin >> K;
	InsertAndOutput(H, K);
	for (int i = 1; i < N; i++)
	{
		cin >> K;
		cout << " ";
		InsertAndOutput(H, K);
	}
	cout << endl;
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
