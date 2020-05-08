// 5_11_线性探测法的查找函数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//函数Find应根据裁判定义的散列函数Hash( Key, H->TableSize )从散列表H中查到Key的位置并返回。如果Key不存在，则返回线性探测法找到的第一个空单元的位置；若没有空单元，则返回ERROR。

#include <iostream>
#define MAXTABLESIZE 100000  /* 允许开辟的最大散列表长度 */
typedef int ElementType;     /* 关键词类型用整型 */
typedef int Index;           /* 散列地址类型 */
typedef Index Position;      /* 数据所在位置与散列地址是同一类型 */
/* 散列单元状态类型，分别对应：有合法元素、空单元、有已删除元素 */
typedef enum { Legitimate, Empty, Deleted } EntryType;

typedef struct HashEntry Cell; /* 散列表单元类型 */
struct HashEntry {
	ElementType Data; /* 存放元素 */
	EntryType Info;   /* 单元状态 */
};

typedef struct TblNode* HashTable; /* 散列表类型 */
struct TblNode {   /* 散列表结点定义 */
	int TableSize; /* 表的最大长度 */
	Cell* Cells;   /* 存放散列单元数据的数组 */
};

HashTable BuildTable(); /* 裁判实现，细节不表 */
Position Hash(ElementType Key, int TableSize)
{
	return (Key % TableSize);
}

#define ERROR -1
Position Find(HashTable H, ElementType Key);

int main()
{
	HashTable H;
	ElementType Key;
	Position P;

	H = BuildTable();
	scanf("%d", &Key);
	P = Find(H, Key);
	if (P == ERROR)
		printf("ERROR: %d is not found and the table is full.\n", Key);
	else if (H->Cells[P].Info == Legitimate)
		printf("%d is at position %d.\n", Key, P);
	else
		printf("%d is not found.  Position %d is returned.\n", Key, P);

	return 0;
}

/* 你的代码将被嵌在这里 */
Position Find(HashTable H, ElementType Key)
{
	int CurrentPos, NewPos;
	NewPos = CurrentPos = Hash(Key, H->TableSize); /* 初始散列位置 */
	/* 当该位置的单元非空，并且不是要找的元素时，发生冲突 */
	while (H->Cells[NewPos].Info != Empty && H->Cells[NewPos].Data != Key) {
		NewPos = (NewPos + 1) % H->TableSize;
		if (NewPos == CurrentPos) return ERROR;
	}
	return NewPos; /* 此时NewPos或者是Key的位置，或者是一个空单元的位置（表示找不到）*/
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
