// 5_12_分离链接法的删除操作函数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string.h>

#define KEYLENGTH 15                   /* 关键词字符串的最大长度 */
typedef char ElementType[KEYLENGTH + 1]; /* 关键词类型用字符串 */
typedef int Index;                     /* 散列地址类型 */

typedef struct LNode* PtrToLNode;
struct LNode {
	ElementType Data;
	PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

typedef struct TblNode* HashTable; /* 散列表类型 */
struct TblNode {   /* 散列表结点定义 */
	int TableSize; /* 表的最大长度 */
	List Heads;    /* 指向链表头结点的数组 */
};

Index Hash(ElementType Key, int TableSize)
{
	return (Key[0] - 'a') % TableSize;
}

HashTable BuildTable(); /* 裁判实现，细节不表 */
bool Delete(HashTable H, ElementType Key);

int main()
{
	HashTable H;
	ElementType Key;

	H = BuildTable();
	scanf("%s", Key);
	if (Delete(H, Key) == false)
		printf("ERROR: %s is not found\n", Key);
	if (Delete(H, Key) == true)
		printf("Are you kidding me?\n");
	return 0;
}

/* 你的代码将被嵌在这里 */
bool Delete(HashTable H, ElementType Key) {
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

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
