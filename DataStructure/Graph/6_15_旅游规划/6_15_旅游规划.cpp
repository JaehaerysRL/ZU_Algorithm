// 6_15_旅游规划.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

/* 图的邻接矩阵表示法 */
#define MaxVertexNum 500    /* 最大顶点数设为100 */
#define INFINITY 65535        /* ∞设为双字节无符号整数的最大值65535*/
typedef int Vertex;         /* 用顶点下标表示顶点,为整型 */
typedef int WeightType;        /* 边的权值设为整型 */
typedef char DataType;        /* 顶点存储的数据类型设为字符型 */
/* 边的定义 */
typedef struct ENode* PtrToENode;
struct ENode {
	Vertex V1, V2;      /* 有向边<V1, V2> */
	WeightType Dist, Cost;  /* 权重 */
};
typedef PtrToENode Edge;
/* 图结点的定义 */
typedef struct MGNode* PtrToMGNode;
struct MGNode {
	int Nv;  /* 顶点数 */
	int Ne;  /* 边数   */
	WeightType Dist[MaxVertexNum][MaxVertexNum]; /* 距离 */
	WeightType Cost[MaxVertexNum][MaxVertexNum]; /* 费用 */
	Vertex S, D;
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
			Graph->Dist[V][W] = Graph->Cost[V][W] = INFINITY;

	return Graph;
}
void InsertEdge(MGraph Graph, Edge E)
{
	/* 插入边 <V1, V2> */
	Graph->Dist[E->V1][E->V2] = E->Dist;
	Graph->Cost[E->V1][E->V2] = E->Cost;
	/* 若是无向图，还要插入边<V2, V1> */
	Graph->Dist[E->V2][E->V1] = E->Dist;
	Graph->Cost[E->V2][E->V1] = E->Cost;
}
MGraph BuildMGraph()
{
	MGraph Graph;
	Edge E;
	int Nv, i;

	scanf("%d", &Nv);   /* 读入顶点个数 */
	Graph = CreateMGraph(Nv); /* 初始化有Nv个顶点但没有边的图 */

	scanf("%d", &(Graph->Ne));   /* 读入边数 */
	scanf("%d %d", &(Graph->S), &(Graph->D));   /* 读入起止点 */
	if (Graph->Ne != 0) { /* 如果有边 */
		E = (Edge)malloc(sizeof(struct ENode)); /* 建立边结点 */
		/* 读入边，格式为"起点 终点 权重"，插入邻接矩阵 */
		for (i = 0; i < Graph->Ne; i++) {
			scanf("%d %d %d %d", &E->V1, &E->V2, &E->Dist, &E->Cost);
			/* 注意：如果权重不是整型，Weight的读入格式要改 */
			InsertEdge(Graph, E);
		}
	}

	return Graph;
}

/* 邻接矩阵存储 - 有权图的单源最短路算法 */
#define ERROR -1
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

void Dijkstra(MGraph Graph, int dist[], int cost[], Vertex S)
{
	int collected[MaxVertexNum];
	Vertex V, W;

	/* 初始化：此处默认邻接矩阵中不存在的边用INFINITY表示 */
	for (V = 0; V < Graph->Nv; V++) {
		dist[V] = Graph->Dist[S][V];
		cost[V] = Graph->Cost[S][V];
		collected[V] = false;
	}
	/* 先将起点收入集合 */
	dist[S] = cost[S] = 0;
	collected[S] = true;

	while (1) {
		/* V = 未被收录顶点中dist最小者 */
		V = FindMinDist(Graph, dist, collected);
		if (V == ERROR) /* 若这样的V不存在 */
			break;      /* 算法结束 */
		collected[V] = true;  /* 收录V */
		for (W = 0; W < Graph->Nv; W++) /* 对图中的每个顶点W */
			/* 若W是V的邻接点并且未被收录 */
			if (collected[W] == false && Graph->Dist[V][W] < INFINITY) {
				/* 若收录V使得dist[W]变小 */
				if (dist[V] + Graph->Dist[V][W] < dist[W]) {
					dist[W] = dist[V] + Graph->Dist[V][W]; /* 更新dist[W] */
					cost[W] = cost[V] + Graph->Cost[V][W]; /* 更新dist[W] */
				}
				else if (dist[V] + Graph->Dist[V][W] == dist[W] && cost[V] + Graph->Cost[V][W] < cost[W])
					cost[W] = cost[V] + Graph->Cost[V][W]; /* 更新dist[W] */
			}
	} /* while结束*/
}

int main()
{
	MGraph G = BuildMGraph();
	int* dist = (int*)malloc(sizeof(int) * G->Nv);
	int* cost = (int*)malloc(sizeof(int) * G->Nv);
	Dijkstra(G, dist, cost, G->S);
	cout << dist[G->D] << " " << cost[G->D] << endl;
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
