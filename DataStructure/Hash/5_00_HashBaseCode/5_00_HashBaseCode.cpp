// 5_00_HashBaseCode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <math.h>

/* 开放定址法，整数类型 */

#define MAXTABLESIZE 100000 /* 允许开辟的最大散列表长度 */
typedef int OElementType;    /* 关键词类型用整型 */
/* 散列单元状态类型，分别对应：有合法元素、空单元、有已删除元素 */
typedef enum { Legitimate, Empty, Deleted } EntryType;

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

	while (p <= MAXTABLESIZE) {
		for (i = (int)sqrt(p); i > 2; i--)
			if (!(p % i)) break; /* p不是素数 */
		if (i == 2) break; /* for正常结束，说明p是素数 */
		else  p += 2; /* 否则试探下一个奇数 */
	}
	return p;
}

int Hash(OElementType Key, int TableSize) {

	return Key % TableSize;
}

OHashTable CreateOTable(int TableSize)
{
	OHashTable H;
	int i;

	H = (OHashTable)malloc(sizeof(struct OTblNode));
	/* 保证散列表最大长度是素数 */
	H->TableSize = NextPrime(TableSize);
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
		/* 字符串类型的关键词需要 strcmp 函数!! */
/* 统计1次冲突，并判断奇偶次 */
		if (++CNum % 2) { /* 奇数次冲突 */
			NewPos = CurrentPos + (CNum + 1) * (CNum + 1) / 4; /* 增量为+[(CNum+1)/2]^2 */
			if (NewPos >= H->TableSize)
				NewPos = NewPos % H->TableSize; /* 调整为合法地址 */
		}
		else { /* 偶数次冲突 */
			NewPos = CurrentPos - CNum * CNum / 4; /* 增量为-(CNum/2)^2 */
			while (NewPos < 0)
				NewPos += H->TableSize; /* 调整为合法地址 */
		}
	}
	return NewPos; /* 此时NewPos或者是Key的位置，或者是一个空单元的位置（表示找不到）*/
}

bool Insert(OHashTable H, OElementType Key)
{
	int Pos = Find(H, Key); /* 先检查Key是否已经存在 */

	if (H->Cells[Pos].Info != Legitimate) { /* 如果这个单元没有被占，说明Key可以插入在此 */
		H->Cells[Pos].Info = Legitimate;
		H->Cells[Pos].Data = Key;
		/*字符串类型的关键词需要 strcpy 函数!! */
		return true;
	}
	else {
		printf("键值已存在");
		return false;
	}
}

/* 分离连接法，字符串类型 */

#define KEYLENGTH 15                   /* 关键词字符串的最大长度 */
typedef char LElementType[KEYLENGTH + 1]; /* 关键词类型用字符串 */
typedef int Index;                     /* 散列地址类型 */
/******** 以下是单链表的定义 ********/
typedef struct LNode* PtrToLNode;
struct LNode {
	LElementType Data;
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

LHashTable CreateTable(int TableSize)
{
	LHashTable H;
	int i;

	H = (LHashTable)malloc(sizeof(struct LTblNode));
	/* 保证散列表最大长度是素数，具体见代码5.3 */
	H->TableSize = NextPrime(TableSize);

	/* 以下分配链表头结点数组 */
	H->Heads = (List)malloc(H->TableSize * sizeof(struct LNode));
	/* 初始化表头结点 */
	for (i = 0; i < H->TableSize; i++) {
		H->Heads[i].Data[0] = '\0';
		H->Heads[i].Next = NULL;
	}

	return H;
}

int Hash(char* Key, int TableSize) {
	unsigned int H;
	while (*Key != '\0')
		H = (H << 5) + *Key++;
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

bool Insert(LHashTable H, LElementType Key)
{
	Position P, NewCell;
	Index Pos;

	P = Find(H, Key);
	if (!P) { /* 关键词未找到，可以插入 */
		NewCell = (Position)malloc(sizeof(struct LNode));
		strcpy(NewCell->Data, Key);
		Pos = Hash(Key, H->TableSize); /* 初始散列位置 */
		/* 将NewCell插入为H->Heads[Pos]链表的第1个结点 */
		NewCell->Next = H->Heads[Pos].Next;
		H->Heads[Pos].Next = NewCell;
		return true;
	}
	else { /* 关键词已存在 */
		printf("键值已存在");
		return false;
	}
}

bool Delete(LHashTable H, LElementType Key) {
	Position P, t;
	Index Pos;
	Pos = Hash(Key, H->TableSize);
	P = H->Heads + Pos;
	while (P->Next && strcmp(P->Next->Data, Key))
		P = P->Next;
	if (!P->Next) return false;
	else {
		t = P->Next;
		P->Next = t->Next;
		free(t);
		printf("%s is deleted from list Heads[%d]\n", Key, Pos);
		return true;
	}
}

void DestroyTable(LHashTable H)
{
	int i;
	Position P, Tmp;

	/* 释放每个链表的结点 */
	for (i = 0; i < H->TableSize; i++) {
		P = H->Heads[i].Next;
		while (P) {
			Tmp = P->Next;
			free(P);
			P = Tmp;
		}
	}
	free(H->Heads); /* 释放头结点数组 */
	free(H);        /* 释放散列表结点 */
}

int main()
{
    std::cout << "Hello World!\n";
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
