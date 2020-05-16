// 6_26_最短工期.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

/* 图的邻接表表示法 */
#define MaxVertexNum 100    /* 最大顶点数设为100 */
typedef int Vertex;         /* 用顶点下标表示顶点,为整型 */
typedef int WeightType;        /* 边的权值设为整型 */
/* 边的定义 */
typedef struct ENode* PtrToENode;
struct ENode {
	Vertex V1, V2;      /* 有向边<V1, V2> */
	WeightType Weight;  /* 权重 */
};
typedef PtrToENode Edge;
/* 邻接点的定义 */
typedef struct AdjVNode* PtrToAdjVNode;
struct AdjVNode {
	Vertex AdjV;        /* 邻接点下标 */
	WeightType Weight;  /* 边权重 */
	PtrToAdjVNode Next;    /* 指向下一个邻接点的指针 */
};
/* 顶点表头结点的定义 */
typedef struct Vnode {
	PtrToAdjVNode FirstEdge;/* 边表头指针 */
} AdjList[MaxVertexNum];    /* AdjList是邻接表类型 */
/* 图结点的定义 */
typedef struct LGNode* PtrToLGNode;
struct LGNode {
	int Nv;     /* 顶点数 */
	int Ne;     /* 边数   */
	AdjList G;  /* 邻接表 */
};
typedef PtrToLGNode LGraph; /* 以邻接表方式存储的图类型 */

LGraph CreateLGraph(int VertexNum)
{ /* 初始化一个有VertexNum个顶点但没有边的图 */
	Vertex V;
	LGraph Graph;

	Graph = (LGraph)malloc(sizeof(struct LGNode)); /* 建立图 */
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	/* 初始化邻接表头指针 */
	/* 注意：这里默认顶点编号从0开始，到(Graph->Nv - 1) */
	for (V = 0; V < Graph->Nv; V++)
		Graph->G[V].FirstEdge = NULL;

	return Graph;
}
void InsertEdge(LGraph Graph, Edge E)
{
	PtrToAdjVNode NewNode;

	/* 插入边 <V1, V2> */
	/* 为V2建立新的邻接点 */
	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V2;
	NewNode->Weight = E->Weight;
	/* 将V2插入V1的表头 */
	NewNode->Next = Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge = NewNode;
}
LGraph BuildLGraph()
{
	LGraph Graph;
	Edge E;
	int Nv, i;

	scanf_s("%d", &Nv);   /* 读入顶点个数 */
	Graph = CreateLGraph(Nv); /* 初始化有Nv个顶点但没有边的图 */

	scanf_s("%d", &(Graph->Ne));   /* 读入边数 */
	if (Graph->Ne != 0) { /* 如果有边 */
		E = (Edge)malloc(sizeof(struct ENode)); /* 建立边结点 */
		/* 读入边，格式为"起点 终点 权重"，插入邻接矩阵 */
		for (i = 0; i < Graph->Ne; i++) {
			scanf_s("%d %d %d", &E->V1, &E->V2, &E->Weight);
			InsertEdge(Graph, E);
		}
	}
	return Graph;
}

/* 图结点队列的定义 */
#define ERROR -1
typedef struct QNode* Queue;
struct QNode
{
	Vertex* Data;
	int Front, Rear;
	int MaxSize;
};
Queue CreateQueue(int MaxSize) {
	Queue Q = (Queue)malloc(sizeof(struct QNode));
	Q->Data = (Vertex*)malloc(MaxSize * sizeof(Vertex));
	Q->Front = Q->Rear = 0;
	Q->MaxSize = MaxSize;
	return Q;
}
bool IsFull(Queue Q) {
	return ((Q->Rear + 1) % Q->MaxSize == Q->Front);
}
bool AddQ(Queue Q, Vertex X) {
	if (IsFull(Q)) {
		return false;
	}
	else {
		Q->Rear = (Q->Rear + 1) % Q->MaxSize;
		Q->Data[Q->Rear] = X;
		return true;
	}
}
bool IsEmpty(Queue Q) {
	return (Q->Rear == Q->Front);
}
Vertex DeleteQ(Queue Q) {
	if (IsEmpty(Q)) {
		return false;
	}
	else {
		Q->Front = (Q->Front + 1) % Q->MaxSize;
		return Q->Data[Q->Front];
	}
}

/* 邻接表存储 - 拓扑排序算法 */
int dis[MaxVertexNum] = { 0 };
int TopSort(LGraph Graph, Vertex TopOrder[])
{ /* 对Graph进行拓扑排序,  TopOrder[]顺序存储排序后的顶点下标 */
	int Indegree[MaxVertexNum], cnt, max, td;
	Vertex V;
	PtrToAdjVNode W;
	Queue Q = CreateQueue(Graph->Nv);

	/* 初始化Indegree[] */
	for (V = 0; V < Graph->Nv; V++)
		Indegree[V] = 0;

	/* 遍历图，得到Indegree[] */
	for (V = 0; V < Graph->Nv; V++)
		for (W = Graph->G[V].FirstEdge; W; W = W->Next)
			Indegree[W->AdjV]++; /* 对有向边<V, W->AdjV>累计终点的入度 */

	/* 将所有入度为0的顶点入列 */
	for (V = 0; V < Graph->Nv; V++)
		if (Indegree[V] == 0)
			AddQ(Q, V);

	/* 下面进入拓扑排序 */
	cnt = 0;
	max = 0;
	while (!IsEmpty(Q)) {
		V = DeleteQ(Q); /* 弹出一个入度为0的顶点 */
		TopOrder[cnt++] = V; /* 将之存为结果序列的下一个元素 */
		/* 对V的每个邻接点W->AdjV */
		for (W = Graph->G[V].FirstEdge; W; W = W->Next)
			if (--Indegree[W->AdjV] == 0)/* 若删除V使得W->AdjV入度为0 */ 
			{
				AddQ(Q, W->AdjV); /* 则该顶点入列 */
				td = dis[V] + W->Weight;
				if (dis[W->AdjV] < td) dis[W->AdjV] = td;
				if (td > max) max = td;
			}		
	} /* while结束*/

	if (cnt != Graph->Nv)
		return -1; /* 说明图中有回路, 返回不成功标志 */
	else
		return max;
}

int main()
{
	LGraph G = BuildLGraph();
	Vertex TopOrder[MaxVertexNum];
	int ans = TopSort(G, TopOrder);
	if (ans < 0) cout << "Impossible" << endl;
	else cout << ans << endl;
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
