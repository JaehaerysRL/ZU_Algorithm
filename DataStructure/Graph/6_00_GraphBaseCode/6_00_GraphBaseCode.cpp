// 6_00_GraphBaseCode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

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

/* 图的邻接矩阵表示法 */

#define MaxVertexNum 100    /* 最大顶点数设为100 */
#define INFINITY 65535        /* ∞设为双字节无符号整数的最大值65535*/
typedef int Vertex;         /* 用顶点下标表示顶点,为整型 */
typedef int WeightType;        /* 边的权值设为整型 */
typedef char DataType;        /* 顶点存储的数据类型设为字符型 */

/* 边的定义 */
typedef struct ENode* PtrToENode;
struct ENode {
	Vertex V1, V2;      /* 有向边<V1, V2> */
	WeightType Weight;  /* 权重 */
};
typedef PtrToENode Edge;
/* 图结点的定义 */
typedef struct MGNode* PtrToMGNode;
struct MGNode {
	int Nv;  /* 顶点数 */
	int Ne;  /* 边数   */
	WeightType G[MaxVertexNum][MaxVertexNum]; /* 邻接矩阵 */
	DataType Data[MaxVertexNum];      /* 存顶点的数据 */
	/* 注意：很多情况下，顶点无数据，此时Data[]可以不用出现 */
};
typedef PtrToMGNode MGraph; /* 以邻接矩阵存储的图类型 */


MGraph CreateMGraph(int VertexNum)
{ /* 初始化一个有VertexNum个顶点但没有边的图 */
	Vertex V, W;
	MGraph Graph;

	Graph = (MGraph)malloc(sizeof(struct MGNode)); /* 建立图 */
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	/* 初始化邻接矩阵 */
	/* 注意：这里默认顶点编号从0开始，到(Graph->Nv - 1) */
	for (V = 0; V < Graph->Nv; V++)
		for (W = 0; W < Graph->Nv; W++)
			Graph->G[V][W] = INFINITY;

	return Graph;
}

void InsertEdge(MGraph Graph, Edge E)
{
	/* 插入边 <V1, V2> */
	Graph->G[E->V1][E->V2] = E->Weight;
	/* 若是无向图，还要插入边<V2, V1> */
	Graph->G[E->V2][E->V1] = E->Weight;
}

MGraph BuildMGraph()
{
	MGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;

	scanf("%d", &Nv);   /* 读入顶点个数 */
	Graph = CreateMGraph(Nv); /* 初始化有Nv个顶点但没有边的图 */

	scanf("%d", &(Graph->Ne));   /* 读入边数 */
	if (Graph->Ne != 0) { /* 如果有边 */
		E = (Edge)malloc(sizeof(struct ENode)); /* 建立边结点 */
		/* 读入边，格式为"起点 终点 权重"，插入邻接矩阵 */
		for (i = 0; i < Graph->Ne; i++) {
			scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
			/* 注意：如果权重不是整型，Weight的读入格式要改 */
			InsertEdge(Graph, E);
		}
	}

	/* 如果顶点有数据的话，读入数据 */
	for (V = 0; V < Graph->Nv; V++)
		scanf(" %c", &(Graph->Data[V]));

	return Graph;
}

/* 邻接矩阵存储的图的遍历*/
/* IsEdge(Graph, V, W)检查<V, W>是否图Graph中的一条边，即W是否V的邻接点。  */
/* 此函数根据图的不同类型要做不同的实现，关键取决于对不存在的边的表示方法。*/
/* 例如对有权图, 如果不存在的边被初始化为INFINITY, 则函数实现如下:         */
bool IsEdge(MGraph Graph, Vertex V, Vertex W)
{
	return Graph->G[V][W] < INFINITY ? true : false;
}
void Visit(Vertex V)
{
	printf("正在访问顶点%d\n", V);
}
/* Visited[]为全局变量，已经初始化为false */
bool Visited[MaxVertexNum] = { false };

/* 邻接矩阵存储的图 - DFS */
void DFS(MGraph Graph, Vertex S, void (*Visit)(Vertex)) {
	Vertex W;

	Visit(S);
	Visited[S] = true; /* 标记S已访问 */

	for (W = 0; W < Graph->Nv; W++) /* 对图中的每个顶点W */
			/* 若W是V的邻接点并且未访问过 */
		if (!Visited[W] && IsEdge(Graph, S, W))
			DFS(Graph, W, Visit);
}

/* 邻接矩阵存储的图 - BFS */
void BFS(MGraph Graph, Vertex S, void (*Visit)(Vertex))
{   /* 以S为出发点对邻接矩阵存储的图Graph进行BFS搜索 */
	Queue Q;
	Vertex V, W;

	Q = CreateQueue(MaxVertexNum); /* 创建空队列, MaxSize为外部定义的常数 */
	/* 访问顶点S：此处可根据具体访问需要改写 */
	Visit(S);
	Visited[S] = true; /* 标记S已访问 */
	AddQ(Q, S); /* S入队列 */

	while (!IsEmpty(Q)) {
		V = DeleteQ(Q);  /* 弹出V */
		for (W = 0; W < Graph->Nv; W++) /* 对图中的每个顶点W */
			/* 若W是V的邻接点并且未访问过 */
			if (!Visited[W] && IsEdge(Graph, V, W)) {
				/* 访问顶点W */
				Visit(W);
				Visited[W] = true; /* 标记W已访问 */
				AddQ(Q, W); /* W入队列 */
			}
	} /* while结束*/
}




/* 图的邻接表表示法 */

#define MaxVertexNum 100    /* 最大顶点数设为100 */
typedef int Vertex;         /* 用顶点下标表示顶点,为整型 */
typedef int WeightType;        /* 边的权值设为整型 */
typedef char DataType;        /* 顶点存储的数据类型设为字符型 */

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
	DataType Data;            /* 存顶点的数据 */
	/* 注意：很多情况下，顶点无数据，此时Data可以不用出现 */
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

	/* 若是无向图，还要插入边 <V2, V1> */
	/* 为V1建立新的邻接点 */
	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V1;
	NewNode->Weight = E->Weight;
	/* 将V1插入V2的表头 */
	NewNode->Next = Graph->G[E->V2].FirstEdge;
	Graph->G[E->V2].FirstEdge = NewNode;
}

LGraph BuildLGraph()
{
	LGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;

	scanf("%d", &Nv);   /* 读入顶点个数 */
	Graph = CreateLGraph(Nv); /* 初始化有Nv个顶点但没有边的图 */

	scanf("%d", &(Graph->Ne));   /* 读入边数 */
	if (Graph->Ne != 0) { /* 如果有边 */
		E = (Edge)malloc(sizeof(struct ENode)); /* 建立边结点 */
		/* 读入边，格式为"起点 终点 权重"，插入邻接矩阵 */
		for (i = 0; i < Graph->Ne; i++) {
			scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
			/* 注意：如果权重不是整型，Weight的读入格式要改 */
			InsertEdge(Graph, E);
		}
	}

	/* 如果顶点有数据的话，读入数据 */
	for (V = 0; V < Graph->Nv; V++)
		scanf(" %c", &(Graph->G[V].Data));

	return Graph;
}

/* 邻接表存储的图的遍历*/
void Visit(Vertex V)
{
	printf("正在访问顶点%d\n", V);
}
/* Visited[]为全局变量，已经初始化为false */
bool Visited[MaxVertexNum] = { false };

/* 邻接表存储的图 - DFS */
void DFS(LGraph Graph, Vertex V, void (*Visit)(Vertex))
{   /* 以V为出发点对邻接表存储的图Graph进行DFS搜索 */
	PtrToAdjVNode W;

	Visit(V); /* 访问第V个顶点 */
	Visited[V] = true; /* 标记V已访问 */

	for (W = Graph->G[V].FirstEdge; W; W = W->Next) /* 对V的每个邻接点W->AdjV */
		if (!Visited[W->AdjV])    /* 若W->AdjV未被访问 */
			DFS(Graph, W->AdjV, Visit);    /* 则递归访问之 */
}

/* 邻接表存储的图 - BFS */
void BFS(LGraph Graph, Vertex S, void (*Visit)(Vertex)) {
	Queue Q;
	Vertex V;
	PtrToAdjVNode W;

	Q = CreateQueue(MaxVertexNum);
	Visit(S);
	Visited[S] = true; /* 标记S已访问 */
	AddQ(Q, S); /* S入队列 */

	while (!IsEmpty(Q)) {
		V = DeleteQ(Q);
		for (W = Graph->G[V].FirstEdge; W; W = W->Next)
			if (!Visited[W->AdjV]) {
				Visit(W->AdjV);
				Visited[W->AdjV] = true; /* 标记W已访问 */
				AddQ(Q, W->AdjV); /* W入队列 */
			}
	} /* while结束*/
}



/* 邻接表存储 - 无权图的单源最短路算法 */

/* dist[]和path[]全部初始化为-1 */
void Unweighted(LGraph Graph, int dist[], int path[], Vertex S)
{
	Queue Q;
	Vertex V;
	PtrToAdjVNode W;

	Q = CreateQueue(Graph->Nv); /* 创建空队列, MaxSize为外部定义的常数 */
	dist[S] = 0; /* 初始化源点 */
	AddQ(Q, S);

	while (!IsEmpty(Q)) {
		V = DeleteQ(Q);
		for (W = Graph->G[V].FirstEdge; W; W = W->Next) /* 对V的每个邻接点W->AdjV */
			if (dist[W->AdjV] == -1) { /* 若W->AdjV未被访问过 */
				dist[W->AdjV] = dist[V] + 1; /* W->AdjV到S的距离更新 */
				path[W->AdjV] = V; /* 将V记录在S到W->AdjV的路径上 */
				AddQ(Q, W->AdjV);
			}
	} /* while结束*/
}

/* 邻接矩阵存储 - 有权图的单源最短路算法 */

Vertex FindMinDist(MGraph Graph, int dist[], int collected[])
{ /* 返回未被收录顶点中dist最小者 */
	Vertex MinV, V;
	int MinDist = INFINITY;

	for (V = 0; V < Graph->Nv; V++) {
		if (collected[V] == false && dist[V] < MinDist) {
			/* 若V未被收录，且dist[V]更小 */
			MinDist = dist[V]; /* 更新最小距离 */
			MinV = V; /* 更新对应顶点 */
		}
	}
	if (MinDist < INFINITY) /* 若找到最小dist */
		return MinV; /* 返回对应的顶点下标 */
	else return ERROR;  /* 若这样的顶点不存在，返回错误标记 */
}

bool Dijkstra(MGraph Graph, int dist[], int path[], Vertex S)
{
	int collected[MaxVertexNum];
	Vertex V, W;

	/* 初始化：此处默认邻接矩阵中不存在的边用INFINITY表示 */
	for (V = 0; V < Graph->Nv; V++) {
		dist[V] = Graph->G[S][V];
		if (dist[V] < INFINITY)
			path[V] = S;
		else
			path[V] = -1;
		collected[V] = false;
	}
	/* 先将起点收入集合 */
	dist[S] = 0;
	collected[S] = true;

	while (1) {
		/* V = 未被收录顶点中dist最小者 */
		V = FindMinDist(Graph, dist, collected);
		if (V == ERROR) /* 若这样的V不存在 */
			break;      /* 算法结束 */
		collected[V] = true;  /* 收录V */
		for (W = 0; W < Graph->Nv; W++) /* 对图中的每个顶点W */
			/* 若W是V的邻接点并且未被收录 */
			if (collected[W] == false && Graph->G[V][W] < INFINITY) {
				if (Graph->G[V][W] < 0) /* 若有负边 */
					return false; /* 不能正确解决，返回错误标记 */
				/* 若收录V使得dist[W]变小 */
				if (dist[V] + Graph->G[V][W] < dist[W]) {
					dist[W] = dist[V] + Graph->G[V][W]; /* 更新dist[W] */
					path[W] = V; /* 更新S到W的路径 */
				}
			}
	} /* while结束*/
	return true; /* 算法执行完毕，返回正确标记 */
}

/* 邻接矩阵存储 - 多源最短路算法 */

bool Floyd(MGraph Graph, WeightType D[][MaxVertexNum], Vertex path[][MaxVertexNum])
{
	Vertex i, j, k;

	/* 初始化 */
	for (i = 0; i < Graph->Nv; i++)
		for (j = 0; j < Graph->Nv; j++) {
			D[i][j] = Graph->G[i][j];
			path[i][j] = -1;
		}

	for (k = 0; k < Graph->Nv; k++)
		for (i = 0; i < Graph->Nv; i++)
			for (j = 0; j < Graph->Nv; j++)
				if (D[i][k] + D[k][j] < D[i][j]) {
					D[i][j] = D[i][k] + D[k][j];
					if (i == j && D[i][j] < 0) /* 若发现负值圈 */
						return false; /* 不能正确解决，返回错误标记 */
					path[i][j] = k;
				}
	return true; /* 算法执行完毕，返回正确标记 */
}

/* 邻接矩阵存储 - Prim最小生成树算法 */

Vertex FindMinDist(MGraph Graph, WeightType dist[])
{ /* 返回未被收录顶点中dist最小者 */
	Vertex MinV, V;
	WeightType MinDist = INFINITY;

	for (V = 0; V < Graph->Nv; V++) {
		if (dist[V] != 0 && dist[V] < MinDist) {
			/* 若V未被收录，且dist[V]更小 */
			MinDist = dist[V]; /* 更新最小距离 */
			MinV = V; /* 更新对应顶点 */
		}
	}
	if (MinDist < INFINITY) /* 若找到最小dist */
		return MinV; /* 返回对应的顶点下标 */
	else return ERROR;  /* 若这样的顶点不存在，返回-1作为标记 */
}

int Prim(MGraph Graph, LGraph MST)
{ /* 将最小生成树保存为邻接表存储的图MST，返回最小权重和 */
	WeightType dist[MaxVertexNum], TotalWeight;
	Vertex parent[MaxVertexNum], V, W;
	int VCount;
	Edge E;

	/* 初始化。默认初始点下标是0 */
	for (V = 0; V < Graph->Nv; V++) {
		/* 这里假设若V到W没有直接的边，则Graph->G[V][W]定义为INFINITY */
		dist[V] = Graph->G[0][V];
		parent[V] = 0; /* 暂且定义所有顶点的父结点都是初始点0 */
	}
	TotalWeight = 0; /* 初始化权重和     */
	VCount = 0;      /* 初始化收录的顶点数 */
	/* 创建包含所有顶点但没有边的图。注意用邻接表版本 */
	MST = CreateLGraph(Graph->Nv);
	E = (Edge)malloc(sizeof(struct ENode)); /* 建立空的边结点 */

	/* 将初始点0收录进MST */
	dist[0] = 0;
	VCount++;
	parent[0] = -1; /* 当前树根是0 */

	while (1) {
		V = FindMinDist(Graph, dist);
		/* V = 未被收录顶点中dist最小者 */
		if (V == ERROR) /* 若这样的V不存在 */
			break;   /* 算法结束 */

		/* 将V及相应的边<parent[V], V>收录进MST */
		E->V1 = parent[V];
		E->V2 = V;
		E->Weight = dist[V];
		InsertEdge(MST, E);
		TotalWeight += dist[V];
		dist[V] = 0;
		VCount++;

		for (W = 0; W < Graph->Nv; W++) /* 对图中的每个顶点W */
			if (dist[W] != 0 && Graph->G[V][W] < INFINITY) {
				/* 若W是V的邻接点并且未被收录 */
				if (Graph->G[V][W] < dist[W]) {
					/* 若收录V使得dist[W]变小 */
					dist[W] = Graph->G[V][W]; /* 更新dist[W] */
					parent[W] = V; /* 更新树 */
				}
			}
	} /* while结束*/
	if (VCount < Graph->Nv) /* MST中收的顶点不到|V|个 */
		TotalWeight = ERROR;
	return TotalWeight;   /* 算法执行完毕，返回最小权重和或错误标记 */
}

/* 邻接表存储 - Kruskal最小生成树算法 */

/*-------------------- 顶点并查集定义 --------------------*/
typedef Vertex ElementType; /* 默认元素可以用非负整数表示 */
typedef Vertex SetName;     /* 默认用根结点的下标作为集合名称 */
typedef ElementType SetType[MaxVertexNum]; /* 假设集合元素下标从0开始 */

void InitializeVSet(SetType S, int N)
{ /* 初始化并查集 */
	ElementType X;

	for (X = 0; X < N; X++) S[X] = -1;
}

void Union(SetType S, SetName Root1, SetName Root2)
{ /* 这里默认Root1和Root2是不同集合的根结点 */
	/* 保证小集合并入大集合 */
	if (S[Root2] < S[Root1]) { /* 如果集合2比较大 */
		S[Root2] += S[Root1];     /* 集合1并入集合2  */
		S[Root1] = Root2;
	}
	else {                         /* 如果集合1比较大 */
		S[Root1] += S[Root2];     /* 集合2并入集合1  */
		S[Root2] = Root1;
	}
}

SetName Find(SetType S, ElementType X)
{ /* 默认集合元素全部初始化为-1 */
	if (S[X] < 0) /* 找到集合的根 */
		return X;
	else
		return S[X] = Find(S, S[X]); /* 路径压缩 */
}

bool CheckCycle(SetType VSet, Vertex V1, Vertex V2)
{ /* 检查连接V1和V2的边是否在现有的最小生成树子集中构成回路 */
	Vertex Root1, Root2;

	Root1 = Find(VSet, V1); /* 得到V1所属的连通集名称 */
	Root2 = Find(VSet, V2); /* 得到V2所属的连通集名称 */

	if (Root1 == Root2) /* 若V1和V2已经连通，则该边不能要 */
		return false;
	else { /* 否则该边可以被收集，同时将V1和V2并入同一连通集 */
		Union(VSet, Root1, Root2);
		return true;
	}
}
/*-------------------- 并查集定义结束 --------------------*/

/*-------------------- 边的最小堆定义 --------------------*/
void PercDown(Edge ESet, int p, int N)
{ /* 改编代码4.24的PercDown( MaxHeap H, int p )    */
  /* 将N个元素的边数组中以ESet[p]为根的子堆调整为关于Weight的最小堆 */
	int Parent, Child;
	struct ENode X;

	X = ESet[p]; /* 取出根结点存放的值 */
	for (Parent = p; (Parent * 2 + 1) < N; Parent = Child) {
		Child = Parent * 2 + 1;
		if ((Child != N - 1) && (ESet[Child].Weight > ESet[Child + 1].Weight))
			Child++;  /* Child指向左右子结点的较小者 */
		if (X.Weight <= ESet[Child].Weight) break; /* 找到了合适位置 */
		else  /* 下滤X */
			ESet[Parent] = ESet[Child];
	}
	ESet[Parent] = X;
}

void InitializeESet(LGraph Graph, Edge ESet)
{ /* 将图的边存入数组ESet，并且初始化为最小堆 */
	Vertex V;
	PtrToAdjVNode W;
	int ECount;

	/* 将图的边存入数组ESet */
	ECount = 0;
	for (V = 0; V < Graph->Nv; V++)
		for (W = Graph->G[V].FirstEdge; W; W = W->Next)
			if (V < W->AdjV) { /* 避免重复录入无向图的边，只收V1<V2的边 */
				ESet[ECount].V1 = V;
				ESet[ECount].V2 = W->AdjV;
				ESet[ECount++].Weight = W->Weight;
			}
	/* 初始化为最小堆 */
	for (ECount = Graph->Ne / 2; ECount >= 0; ECount--)
		PercDown(ESet, ECount, Graph->Ne);
}

void Swap(struct ENode* a, struct ENode* b) {
	struct ENode c = *a;
	*a = *b;
	*b = c;
}

int GetEdge(Edge ESet, int CurrentSize)
{ /* 给定当前堆的大小CurrentSize，将当前最小边位置弹出并调整堆 */

	/* 将最小边与当前堆的最后一个位置的边交换 */
	Swap(&ESet[0], &ESet[CurrentSize - 1]);
	/* 将剩下的边继续调整成最小堆 */
	PercDown(ESet, 0, CurrentSize - 1);

	return CurrentSize - 1; /* 返回最小边所在位置 */
}
/*-------------------- 最小堆定义结束 --------------------*/


int Kruskal(LGraph Graph, LGraph MST)
{ /* 将最小生成树保存为邻接表存储的图MST，返回最小权重和 */
	WeightType TotalWeight;
	int ECount, NextEdge;
	SetType VSet; /* 顶点数组 */
	Edge ESet;    /* 边数组 */

	InitializeVSet(VSet, Graph->Nv); /* 初始化顶点并查集 */
	ESet = (Edge)malloc(sizeof(struct ENode) * Graph->Ne);
	InitializeESet(Graph, ESet); /* 初始化边的最小堆 */
	/* 创建包含所有顶点但没有边的图。注意用邻接表版本 */
	MST = CreateLGraph(Graph->Nv);
	TotalWeight = 0; /* 初始化权重和     */
	ECount = 0;      /* 初始化收录的边数 */

	NextEdge = Graph->Ne; /* 原始边集的规模 */
	while (ECount < Graph->Nv - 1) {  /* 当收集的边不足以构成树时 */
		NextEdge = GetEdge(ESet, NextEdge); /* 从边集中得到最小边的位置 */
		if (NextEdge < 0) /* 边集已空 */
			break;
		/* 如果该边的加入不构成回路，即两端结点不属于同一连通集 */
		if (CheckCycle(VSet, ESet[NextEdge].V1, ESet[NextEdge].V2) == true) {
			/* 将该边插入MST */
			InsertEdge(MST, ESet + NextEdge);
			TotalWeight += ESet[NextEdge].Weight; /* 累计权重 */
			ECount++; /* 生成树中边数加1 */
		}
	}
	if (ECount < Graph->Nv - 1)
		TotalWeight = -1; /* 设置错误标记，表示生成树不存在 */

	return TotalWeight;
}

/* 邻接表存储 - 拓扑排序算法 */

bool TopSort(LGraph Graph, Vertex TopOrder[])
{ /* 对Graph进行拓扑排序,  TopOrder[]顺序存储排序后的顶点下标 */
	int Indegree[MaxVertexNum], cnt;
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
	while (!IsEmpty(Q)) {
		V = DeleteQ(Q); /* 弹出一个入度为0的顶点 */
		TopOrder[cnt++] = V; /* 将之存为结果序列的下一个元素 */
		/* 对V的每个邻接点W->AdjV */
		for (W = Graph->G[V].FirstEdge; W; W = W->Next)
			if (--Indegree[W->AdjV] == 0)/* 若删除V使得W->AdjV入度为0 */
				AddQ(Q, W->AdjV); /* 则该顶点入列 */
	} /* while结束*/

	if (cnt != Graph->Nv)
		return false; /* 说明图中有回路, 返回不成功标志 */
	else
		return true;
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
